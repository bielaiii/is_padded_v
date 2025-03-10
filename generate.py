

total_count = 100


def generate():
    with open("generate_match.h", "w") as fp:
        fp.write("#ifndef __PYTHON_GENERATE_MATCH_H__\n#define __PYTHON_GENERATE_MATCH_H__\n\n#include <cstddef>\n\n")
        header_ = "template <typename T, size_t size_>\nconstexpr size_t for_each_field_size() {"
        fp.write(header_ + "\n")
        for i in range(1, total_count + 1):
            item_ = [f"_{x}" for x in range(1, i + 1)]
            fp.write(f"if constexpr (size_ == {i}) {{\n")
            fp.write("    auto && [")
            fp.write(f", ".join(item_))
            fp.write(f"] = T{{}};\n")
            fp.write("    return ")
            fp.write("+".join([f"plain_size<decltype(_{x})>()" for x in range(1, i + 1)]))
            fp.write(";\n}")
            if i > 0:
                fp.write(" else ")
        fp.write(f"{{\nreturn -1;\n}}\n}}\n")

        fp.write("#endif\n")



generate()

