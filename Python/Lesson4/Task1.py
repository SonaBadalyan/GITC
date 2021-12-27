hello = {
    "hy" : "Բարև",
    "en" : "Hello",
    "ru" : "Привет",
    "default" : "Unknown language code"
}

lang_code = input("Input language code: ")

print(hello.get(lang_code, hello["default"]))
