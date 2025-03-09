

total_count = 50


def generate():
    with open("generate_match.h", "w") as fp:
        header_ = "template <typename T, size_t size_>\nconstexpr size_t for_each_field_size() {"
        fp.write(header_ + "\n")
        for i in range(1, total_count + 1):
            item_ = [f"_{x}" for x in range(1, i + 1)]
            fp.write(f"if constexpr (size_ == {i}) {{\n")
            fp.write("    auto && [")
            fp.write(f", ".join(item_))
            fp.write(f"] = T{{}};\n")
            fp.write("    return ")
            fp.write("+".join([f"plain_size<decltype(_{x})>(_{x})" for x in range(1, i + 1)]))
            fp.write(";\n}")
            if i > 1:
                fp.write(" else ")
        fp.write(f"{{\nreturn -1;\n}}\n}}\n")



generate()

