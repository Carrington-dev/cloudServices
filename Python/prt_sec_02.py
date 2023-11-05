from cryptography.fernet import Fernet

# Generate a random encryption key
key = Fernet.generate_key()

# Initialize the encryption object
cipher_suite = Fernet(key)

# Encrypt sensitive data
sensitive_data = b"4111123441231111/456/23-05"
encrypted_data = cipher_suite.encrypt(sensitive_data)

print(encrypted_data)
# Decrypt the data
decrypted_data = cipher_suite.decrypt(encrypted_data)

print(decrypted_data)