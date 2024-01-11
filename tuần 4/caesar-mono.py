def caesar_cipher(text, shift):
    """
    Hàm này mã hóa một chuỗi sử dụng phương pháp mã hóa Caesar
    với số lượng ký tự dịch sang phải là 'shift'

    :param text: Chuỗi cần mã hóa
    :param shift: Số lượng ký tự dịch sang phải
    :return: Chuỗi đã được mã hóa
    """
    result = ""

    # Vòng lặp qua từng ký tự trong chuỗi
    for i in range(len(text)):
        char = text[i]

        # Kiểm tra xem ký tự hiện tại có phải là chữ cái không
        if char.isalpha():
            # Đưa ký tự về dạng chữ thường và tính toán vị trí mới của ký tự
            char = char.lower()
            new_char = chr((ord(char) + shift - 97) % 26 + 97)
            # Thêm ký tự đã mã hóa vào chuỗi kết quả
            result += new_char
        else:
            # Thêm ký tự không phải chữ cái vào chuỗi kết quả
            result += char

    return result


def caesar_decipher(text, shift):
    """
    Hàm này giải mã một chuỗi đã được mã hóa bằng phương pháp mã hóa Caesar
    với số lượng ký tự dịch sang phải là 'shift'

    :param text: Chuỗi cần giải mã
    :param shift: Số lượng ký tự dịch sang phải
    :return: Chuỗi đã được giải mã
    """
    result = ""

    # Vòng lặp qua từng ký tự trong chuỗi
    for i in range(len(text)):
        char = text[i]

        # Kiểm tra xem ký tự hiện tại có phải là chữ cái không
        if char.isalpha():
            # Đưa ký tự về dạng chữ thường và tính toán vị trí mới của ký tự
            char = char.lower()
            new_char = chr((ord(char) - shift - 97) % 26 + 97)

            # Kiểm tra xem ký tự ban đầu là chữ in hoa hay không
            if text[i].isupper():
                new_char = new_char.upper()

            # Thêm ký tự đã giải mã vào chuỗi kết quả
            result += new_char
        else:
            # Thêm ký tự không phải chữ cái vào chuỗi kết quả
            result += char

    return result

import random

def generate_key():
    """
    Hàm này tạo ra một khóa mã hóa ngẫu nhiên cho phương pháp mã hóa monoalphabetic

    :return: Một từ điển biểu diễn khóa mã hóa
    """
    # Tạo một danh sách chứa các chữ cái tiếng Anh
    alphabet = list("abcdefghijklmnopqrstuvwxyz")

    # Trộn ngẫu nhiên các chữ cái trong danh sách để tạo khóa mã hóa
    random.shuffle(alphabet)

    # Tạo một từ điển biểu diễn khóa mã hóa
    key = {}
    for i in range(26):
        key[chr(97+i)] = alphabet[i]

    return key


def monoalphabetic_cipher(text, key):
    """
    Hàm này mã hóa một chuỗi sử dụng phương pháp mã hóa monoalphabetic
    dựa trên khóa mã hóa được cung cấp

    :param text: Chuỗi cần mã hóa
    :param key: Khóa mã hóa
    :return: Chuỗi đã được mã hóa
    """
    result = ""

    # Vòng lặp qua từng ký tự trong chuỗi
    for i in range(len(text)):
        char = text[i]

        # Kiểm tra xem ký tự hiện tại có phải là chữ cái không
        if char.isalpha():
            # Đưa ký tự về dạng chữ thường và tìm ký tự mã hóa trong khóa
            char = char.lower()
            new_char = key[char]
            # Thêm ký tự đã mã hóa vào chuỗi kết quả
            result += new_char
        else:
            # Thêm ký tự không phải chữ cái vào chuỗi kết quả
            result += char

    return result


def monoalphabetic_decipher(text, key):

    """
    Hàm này giải mã một chuỗi đã được mã hóa bằng phương pháp mã hóa monoalphabetic
    dựa trên khóa mã hóa được cung cấp

    :param text: Chuỗi cần giải mã
    :param key: Khóa mã hóa
    :return: Chuỗi đã được giải mã
    """
    result = ""

    # Vòng lặp qua từng ký tự trong chuỗi
    for i in range(len(text)):
        char = text[i]

        # Kiểm tra xem ký tự hiện tại có phải là chữ cái không
        if char.isalpha():
            # Đưa ký tự về dạng chữ thường và tìm ký tự giải mã trong khóa
            char = char.lower()
            for k, v in key.items():
                if v == char:
                    result += k
        else:
            # Thêm ký tự không phải chữ cái vào chuỗi kết quả
            result += char
    return result

print("Plaintext: meet me after the toga party")
print("Caesar_cipher (key = 3):")
print(caesar_cipher("meet me after the toga party", 3))
print("Caesar_decipher (key = 3):")
print(caesar_decipher(caesar_cipher("meet me after the toga party", 3), 3))
print("Monoalphabetic_cipher:")
key = generate_key()
print("Generate_key:")
print(key)
mono = monoalphabetic_cipher("meet me after the toga party", key)
print(mono)
print("Monoalphabetic_decipher: ")
print(monoalphabetic_decipher(mono, key))


