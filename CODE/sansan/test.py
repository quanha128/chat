import sys
import requests

url = "http://challenge-server.code-check.io/api/hash"

def main(argv):
    # このコードは引数と標準出力を用いたサンプルコードです。
    # このコードは好きなように編集・削除してもらって構いません。
    # ---
    # This is a sample code to use arguments and outputs.
    # Edit and remove this code as you like.

    # for i, v in enumerate(argv):
    #     print("argv[{0}]: {1}".format(i, v))

    param = {'q':argv[0]}
    r = requests.get(url = url, params=param)
    data = r.json()
    print(data['hash'])




if __name__ == '__main__':
    main(sys.argv[1:])
