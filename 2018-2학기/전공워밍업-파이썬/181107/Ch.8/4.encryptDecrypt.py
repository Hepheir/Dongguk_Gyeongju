plain_text = input()

encrypted_text = ""
for c in plain_text:
    x = ord(c)
    x = x + 1
    cc = chr(x)
    encrypted_text = encrypted_text + cc

print("")
print("Encrypted : " + encrypted_text)

decrypted_text = ""
for c in encrypted_text:
    x = ord(c)
    x = x - 1
    cc = chr(x)
    decrypted_text = decrypted_text + cc

print("Decrypted : " + decrypted_text)
print("")