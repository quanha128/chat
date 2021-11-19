from hashlib import sha512
import pyotp

SECRET_TOKEN = "kokiji.jp@gmail.comHENNGECHALLENGE003"
# KEKW = "kokijijpgmailcomHENNGECHALLENGE003"
KEKW = "kokijijpgmailcomhenngechallenge003"

# generating TOTP codes with provided secret

totp = pyotp.TOTP("ninjaexamplecomHENNGECHALLENGE3", 10, sha512, interval=30)
print(totp.now())

totp = pyotp.TOTP(KEKW, 10, sha512, interval=30)
print(totp.now())