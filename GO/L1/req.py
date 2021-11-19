import requests
import base64
import hmac
import struct
import time

USER_ID = "kokiji.jp@gmail.com"
SECRET_TOKEN = "kokiji.jp@gmail.comHENNGECHALLENGE003"

url = 'https://api.challenge.hennge.com/challenges/003'
data = {
    "github_url": "https://gist.github.com/quanha128/0b834840eec812842b76070e1cc34c47",
    "contact_email": "kokiji.jp@gmail.com"
}

# key = base64.b32encode(b'kokiji.jp@gmail.comHENNGECHALLENGE003')
# key = key.decode("utf-8")

# key = base64.b32encode(b'[B@d716361')
key = base64.b32encode(b'[B@6ff3c5b5')
key = key.decode("utf-8")
print(key)

def hotp(key, counter, digits=10, digest='sha512'):
    key = base64.b32decode(key.upper() + '=' * ((8 - len(key)) % 8))
    print(key)
    counter = struct.pack('>Q', counter)
    mac = hmac.new(key, counter, digest).digest()
    print(mac)
    offset = mac[-1] & 0x0f
    binary = struct.unpack('>L', mac[offset:offset+4])[0] & 0x7fffffff
    return str(binary)[-digits:].zfill(digits)


def totp(key, time_step=30, digits=10, digest='sha512'):
    return hotp(key, int(time.time() / time_step), digits, digest)

password = totp("NNXWW2LKNEXGU4CAM5WWC2LMFZRW63KIIVHE4R2FINEECTCMIVHEORJQGAZQ====", time_step=30, digits=10, digest='sha512')
print(password)

authorizationBasic = base64.b64encode(bytes(USER_ID + ":" + password, 'utf-8'))


headers = {
    "Content-Type": "application/json",
    "Authorization": "Basic " + authorizationBasic.decode("utf-8")
}



print(USER_ID + ":" + password)
print(authorizationBasic.decode("utf-8"))



x = requests.post(url, json=data, headers=headers)

print(x.text)