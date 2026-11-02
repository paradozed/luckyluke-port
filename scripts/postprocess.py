#!/usr/bin/env python3
"""Post-process Ghidra pseudo-C output so it compiles with a real C toolchain.

Usage:
  scripts/postprocess.py <ghidra_c_dir> <lucky_c_path> [--linux]
"""
from __future__ import annotations

import os
import re
import sys


def collect_forward_decls_and_void_funcs(ghidra_c_dir: str):
    fwd_decls = []
    void_funcs = set()
    seen = set()

    for fname in sorted(os.listdir(ghidra_c_dir)):
        if not fname.endswith(".c") or fname == "_index.tsv":
            continue
        fpath = os.path.join(ghidra_c_dir, fname)
        with open(fpath, "r") as f:
            lines = f.readlines()

        clean = []
        for line in lines:
            line = re.sub(r"/\*.*?\*/", "", line)
            line = line.strip()
            if line == "":
                continue
            clean.append(line)

        joined = " ".join(clean)
        semi = joined.find("{")
        if semi < 0:
            semi = joined.find(";")
        if semi < 0:
            continue
        sig = joined[:semi].strip()

        m = re.match(r"^([\w\s*]+?)\s+([A-Za-z_][A-Za-z0-9_]*)\s*\((.*)\)\s*$", sig)
        if not m:
            continue

        ret_type = m.group(1).strip()
        func_name = m.group(2)
        params = m.group(3).strip()

        if not (func_name.startswith("FUN_") or func_name.startswith("_")):
            continue
        if func_name in seen:
            continue
        seen.add(func_name)

        fwd_decls.append(f"extern {ret_type} {func_name}({params});")
        if ret_type.split()[0] == "void":
            void_funcs.add(func_name)

    return fwd_decls, void_funcs


def postprocess(content: str, ghidra_c_dir: str, linux: bool = False) -> str:
    fwd_decls, void_funcs = collect_forward_decls_and_void_funcs(ghidra_c_dir)

    # 1. Function-pointer calls: (*DAT_XXXX(args)) -> ((int (*)(...))DAT_XXXX)(args)
    content = re.sub(r"\(\*DAT_([0-9A-Fa-f]+)\)", r"((int (*)(...))DAT_\1)", content)
    content = re.sub(r"\(\*PTR_([0-9A-Za-z_]+)\)", r"((int (*)(...))PTR_\1)", content)

    # 2. Bare pointer dereference through globals: *DAT_XXXX -> (*(unsigned int *)DAT_XXXX)
    content = re.sub(r"\*DAT_([0-9A-Fa-f]+)(?!\()", r"(*(unsigned int *)DAT_\1)", content)

    # 3. _N_M_ overlapping-field member access as LVALUE
    _lvalue_repls = [
        (r"([A-Za-z_][A-Za-z0-9_]*)\._0_4_\s*=\s*(.+?);", r"\1 = (\2);"),
        (
            r"([A-Za-z_][A-Za-z0-9_]*)\._4_4_\s*=\s*(.+?);",
            r"\1 = (\1 & ~0xFFFFFFFF00000000ull) | ((unsigned long long)(\2) << 32);",
        ),
        (
            r"([A-Za-z_][A-Za-z0-9_]*)\._0_2_\s*=\s*(.+?);",
            r"\1 = (\1 & ~0xFFFFu) | ((unsigned int)(\2) & 0xFFFFu);",
        ),
        (
            r"([A-Za-z_][A-Za-z0-9_]*)\._0_1_\s*=\s*(.+?);",
            r"\1 = (\1 & ~0xFFu) | ((unsigned int)(\2) & 0xFFu);",
        ),
        (
            r"([A-Za-z_][A-Za-z0-9_]*)\._1_3_\s*=\s*(.+?);",
            r"\1 = (\1 & ~0xFFFFFF00u) | ((unsigned int)(\2) & 0xFFFFFF00u);",
        ),
        (
            r"([A-Za-z_][A-Za-z0-9_]*)\._2_2_\s*=\s*(.+?);",
            r"\1 = (\1 & ~0xFFFF0000u) | ((unsigned int)(\2) & 0xFFFF0000u);",
        ),
        (
            r"([A-Za-z_][A-Za-z0-9_]*)\._3_1_\s*=\s*(.+?);",
            r"\1 = (\1 & ~0xFF000000u) | ((unsigned int)(\2) & 0xFF000000u);",
        ),
        (
            r"([A-Za-z_][A-Za-z0-9_]*)\._1_1_\s*=\s*(.+?);",
            r"\1 = (\1 & ~0xFF00u) | ((unsigned int)(\2) & 0xFF00u);",
        ),
    ]
    for pat, repl in _lvalue_repls:
        content = re.sub(pat, repl, content)

    # 4. _N_M_ overlapping-field member access as RVALUE
    repls = [
        (r"([A-Za-z_][A-Za-z0-9_]*)\._0_4_", r"((unsigned int)(\1))"),
        (r"([A-Za-z_][A-Za-z0-9_]*)\._4_4_", r"((unsigned long long)(\1) >> 32)"),
        (r"([A-Za-z_][A-Za-z0-9_]*)\._0_2_", r"((unsigned int)(\1) & 0xFFFFu)"),
        (r"([A-Za-z_][A-Za-z0-9_]*)\._0_1_", r"((unsigned int)(\1) & 0xFFu)"),
        (r"([A-Za-z_][A-Za-z0-9_]*)\._1_3_", r"((unsigned int)(\1) >> 8)"),
        (r"([A-Za-z_][A-Za-z0-9_]*)\._2_2_", r"((unsigned int)(\1) >> 16)"),
        (r"([A-Za-z_][A-Za-z0-9_]*)\._3_1_", r"(((unsigned int)(\1) >> 24) & 0xFFu)"),
        (r"([A-Za-z_][A-Za-z0-9_]*)\._1_1_", r"(((unsigned int)(\1) >> 8) & 0xFFu)"),
        (r"([A-Za-z_][A-Za-z0-9_]*)\._12_2_", r"((unsigned int)(\1) >> 96)"),
        (r"([A-Za-z_][A-Za-z0-9_]*)\._14_2_", r"((unsigned int)(\1) >> 112)"),
        (r"([A-Za-z_][A-Za-z0-9_]*)\._8_4_", r"((unsigned long long)(\1) >> 64)"),
    ]
    for pat, repl in repls:
        content = re.sub(pat, repl, content)

    # 5. Label address: &LAB_XXXX -> &&LAB_XXXX
    content = content.replace("&LAB_", "&&LAB_")

    # 6. _local_XX / _param_ variables -> local_ / param_
    content = re.sub(r"\b_local_(\d+)", r"local_\1", content)
    content = re.sub(r"\b_local_([a-z])", r"local_\1", content)
    content = re.sub(r"\b_param_(\d+)", r"param_\1", content)

    # 7. Missing LABEL definitions -> null pointer
    used_labels = set(re.findall(r"&&(LAB_[0-9A-Fa-f]+)", content))
    defined_labels = set(re.findall(r"^(LAB_[0-9A-Fa-f]+):", content, re.MULTILINE))
    for lab in used_labels - defined_labels:
        content = content.replace(f"&&{lab}", "(void *)0")

    # 8. Void functions called for their return value: strip the assignment
    if void_funcs:
        vf_pattern = "|".join(
            re.escape(vf) for vf in sorted(void_funcs, key=len, reverse=True)
        )
        content = re.sub(
            r"\b([A-Za-z_][A-Za-z0-9_]*)\s*=\s*("
            + vf_pattern
            + r")\s*\((.*?)\)(?!\s*;)",
            lambda m: m.group(2) + "(" + m.group(3) + ")",
            content,
            flags=re.DOTALL,
        )
        content = re.sub(
            r"\b([A-Za-z_][A-Za-z0-9_]*)\s*=\s*\([^)]*\)\s*("
            + vf_pattern
            + r")\s*\((.*?)\)(?!\s*;)",
            lambda m: m.group(2) + "(" + m.group(3) + ")",
            content,
            flags=re.DOTALL,
        )
        content = re.sub(
            r"([A-Za-z_][A-Za-z0-9_]*)\s*=\s*("
            + vf_pattern
            + r")\s*\((.*?)\)\s*;",
            lambda m: m.group(1) + " = 0; " + m.group(2) + "(" + m.group(3) + ");",
            content,
            flags=re.DOTALL,
        )
        content = re.sub(
            r"([A-Za-z_][A-Za-z0-9_]*)\s*=\s*\([^)]*\)\s*("
            + vf_pattern
            + r")\s*\((.*?)\)\s*;",
            lambda m: m.group(1) + " = 0; " + m.group(2) + "(" + m.group(3) + ");",
            content,
            flags=re.DOTALL,
        )
        content = content.replace("(RGBQUAD)__chkesp()", "(RGBQUAD){0}")

    # 9. DAT_XXXX[index] -> (*((unsigned int *)DAT_XXXX + index))
    content = re.sub(
        r"DAT_([0-9A-Fa-f]+)\[([^\]]+)\]",
        r"(*((unsigned int *)DAT_\1 + \2))",
        content,
    )

    # 10. (code **) and (code *) casts -> (ghidra_code_fn **) / (ghidra_code_fn *)
    content = content.replace("(code **)", "(ghidra_code_fn **)")
    content = re.sub(r"\bcode\s+\*", "ghidra_code_fn *", content)

    # 11. LARGE_INTEGER.s -> LARGE_INTEGER.u
    content = content.replace(".s.LowPart", ".u.LowPart")
    content = content.replace(".s.HighPart", ".u.HighPart")

    # 12. local_XX.u.Region.lpLastBlock -> local_XX.u.u2.size
    content = re.sub(
        r"([A-Za-z_][A-Za-z0-9_]*)\.u\.Region\.lpLastBlock\s*=\s*(.*?);",
        r"\1.u.u2.size = \2;",
        content,
    )

    # 13. ((unsigned int)(VAR)) = EXPR -> VAR = (unsigned int)(EXPR)
    content = re.sub(
        r"\(\(unsigned int\)\(([A-Za-z_][A-Za-z0-9_]*)\)\)\s*=\s*(.*?)\s*[;,]",
        r"\1 = (unsigned int)(\2);",
        content,
    )

    # 14. &DAT_XXXX / &_DAT_XXXX / &PTR_XXXX -> ((unsigned int *)VAR)
    content = re.sub(
        r"&((?:_DAT_|DAT_|PTR_)[0-9A-Fa-fA-Za-z_]*)",
        r"((unsigned int *)(\1))",
        content,
    )

    # 15. __chkesp(arg) -> __chkesp()
    content = re.sub(r"__chkesp\([^)]*\)", "__chkesp()", content)

    # 16. Stub function FUN_004925b0 -> make stub accept args
    fwd_decls = [d.replace("void FUN_004925b0(void)", "void FUN_004925b0(void *param_1)") for d in fwd_decls]
    content = content.replace(
        "void FUN_004925b0(void)", "void FUN_004925b0(void *param_1)"
    )
    content = content.replace("FUN_004925b0()", "FUN_004925b0(0)")

    # 17. ) , DAT_ -> ); DAT_  (Ghidra quirk: merged separate statements)
    content = re.sub(
        r"\)\s*,\s*(DAT_[0-9A-Fa-fA-Za-z_]+)\s*=",
        r"); \1 =",
        content,
    )

    # 18. &((undefined1 *)(X) + Y) -> ((unsigned int *)(unsigned char *)(X) + Y)
    content = re.sub(
        r"&\(\(undefined1 \*\)\(([^)]+)\)\s*\+\s*\(([^)]+)\)\)",
        r"((unsigned int *)(unsigned char *)(\1) + (\2))",
        content,
    )

    # 19. Strip .u.LowPart/.u.HighPart from ALL variables with .u. access
    u_var_names = set(re.findall(r"([A-Za-z_][A-Za-z0-9_]*)\.u\.", content))
    if u_var_names:
        u_pattern = "|".join(re.escape(sv) for sv in sorted(u_var_names, key=len, reverse=True))
        content = re.sub(
            r"\b(" + u_pattern + r")\.u\.LowPart\b",
            lambda m: m.group(1),
            content,
        )
        content = re.sub(
            r"\b(" + u_pattern + r")\.u\.HighPart\b",
            "0",
            content,
        )
        content = re.sub(
            r"\(unsigned int\)\(\b(" + u_pattern + r")\b\)",
            lambda m: m.group(1),
            content,
        )

    # 20. undefined8 -> unsigned long long (avoid typedef conflicts)
    print(f"DEBUG step 20: undefined8 count before = {content.count('undefined8')}", file=sys.stderr)
    content = re.sub(r"\bundefined8\b", "unsigned long long", content)
    print(f"DEBUG step 20: undefined8 count after = {content.count('undefined8')}", file=sys.stderr)

    # 21. _PROCESS_HEAP_ENTRY -> PROCESS_HEAP_ENTRY (windows.h defines the latter)
    content = content.replace("_PROCESS_HEAP_ENTRY", "PROCESS_HEAP_ENTRY")
    content = content.replace("_PPROCESS_HEAP_ENTRY", "PPROCESS_HEAP_ENTRY")

    # 22. LARGE_INTEGER vars -> unsigned int (aggregate type issues)
    li_decls = set()
    for decl in re.finditer(r"\bLARGE_INTEGER\s+([A-Za-z_][A-Za-z0-9_]*)\s*[;,]", content):
        li_decls.add(decl.group(1))
    for decl in re.finditer(r"\bLARGE_INTEGER\s+([A-Za-z_][A-Za-z0-9_]*)\s*\[", content):
        li_decls.add(decl.group(1))
    for li_var in li_decls:
        content = re.sub(r"\bLARGE_INTEGER\s+" + re.escape(li_var) + r"\b", "unsigned int " + li_var, content)
    for li_var in li_decls:
        content = re.sub(
            r"\b" + re.escape(li_var) + r"\.u\.LowPart\b",
            li_var,
            content,
        )
        content = re.sub(
            r"\b" + re.escape(li_var) + r"\.u\.HighPart\b",
            "0",
            content,
        )
        content = re.sub(
            r"\(unsigned int\)\(\b" + re.escape(li_var) + r"\b\)",
            li_var,
            content,
        )

    # 23. __nh_malloc_dbg -> __nh_malloc (type conflict with windows.h)
    content = content.replace("__nh_malloc_dbg", "__nh_malloc")
    content = content.replace("__nh_malloc_crt", "__nh_malloc")
    content = content.replace("__nh_malloc_forward", "__nh_malloc")

    # 24. _N_M_ rvalue used as lvalue
    content = re.sub(
        r"\(\(unsigned int\)\(([A-Za-z_][A-Za-z0-9_]*)\)\)\s*>>\s*(\d+)\s*=\s*(.*?);",
        lambda m: (
            f"{m.group(1)} = ({m.group(1)} & ~(0xFFFFFFFFu << {m.group(2)})) | "
            f"((unsigned int)({m.group(3)}) << {m.group(2)});"
        ),
        content,
    )

    # 25. Invalid C: 0 = xxx (Ghidra bug where global assignment becomes constant assignment)
    content = re.sub(
        r"^(\s*)0\s*=\s*(0x[0-9A-Fa-f]+|[0-9]+)\s*;",
        r"\1/* 0 = \2 removed (Ghidra artifact) */;",
        content,
        flags=re.MULTILINE,
    )

    # 26. Semicolon inside condition: (var = expr; cond2) -> (var = expr, cond2)
    content = re.sub(
        r"\(([^;]*?)\s*=\s*([^;]*?)\s*;\s*([^)]*?)\)",
        lambda m: f"({m.group(1)} = {m.group(2)}, {m.group(3)})",
        content,
    )

    # 27. for (init, cond; incr) -> for (init; cond; incr)  (Ghidra for-loop bug)
    content = re.sub(
        r"for\s*\(([^;,]+),\s*([^;]*?)\s*;\s*([^)]*?)\)",
        r"for (\1; \2; \3)",
        content,
    )

    # 28. Insert forward declarations after the includes
    insert_marker = '#include "ghidra_compat.h"'
    if insert_marker in content:
        decls_block = "\n".join(fwd_decls) + "\n\n"
        content = content.replace(insert_marker, insert_marker + "\n" + decls_block, 1)

    return content


def main(argv):
    if len(argv) < 3:
        print(f"usage: {argv[0]} <ghidra_c_dir> <lucky_c_path> [--linux]", file=sys.stderr)
        return 2

    ghidra_c_dir = argv[1]
    lucky_c_path = argv[2]
    linux = len(argv) > 3 and argv[3] == "--linux"

    with open(lucky_c_path, "r") as f:
        content = f.read()

    content = postprocess(content, ghidra_c_dir, linux=linux)

    with open(lucky_c_path, "w") as f:
        f.write(content)

    print("Post-processing done.")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))