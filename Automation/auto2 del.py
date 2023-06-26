import requests
import json

url = "https://uss.rozetka.com.ua/session/cart-se/delete"
product_ids = [288376303,362023689,282286938,346597995,370960626,353689830,353549163,368196027,
               353549349,365576667,372852162,367531242,377214726,363142902,370831845,282334828,
               369755118,371199345,342602632,353548038,359979255,373572861,282363393,372851505,
               377333553,362867265,365578146,372823491,374247741,374737320,383717991,369433923,
               354203376,376273977,371130510,372461553,383708286,368680098,303469643,373867740,
               375934830,359407170,383574957,370897032,347052162,354152424,368680149,363142941,
               372171999,363970554,366636555,365521023,277503488,358169208,362155707,380452476,
               366653697,372460185,361111653,370338309]

headers = {
  'Content-Type': 'application/json',
  'Csrf-Token': 'feuKF63pCE3yW/aEZjhfyZHf2l7rHi/qoYGjNl0Q8m6HHOxG',
  'Cookie': '_uss-csrf=feuKF63pCE3yW/aEZjhfyZHf2l7rHi/qoYGjNl0Q8m6HHOxG; Path=/; Domain=rozetka.com.ua; Expires=Mon, 24 Jun 2024 18:17:15 GMT; Secure ussajwt=eyJhbGciOiJSUzI1NiIsImtpZCI6InVzc2F0LnYwIiwidHlwIjoiSldUIn0.eyJkZXRhaWxzIjoiYTUyNzBlMjRmMTBkYTQzMWEyYjE3NWVkNjVhMDQzMzc0NWNiNDRhMmIwZGFjNjczNTMzMzQwNWMxMjBmMmI4ZmNkNDEwMjhjMDcxYjFjYmVkNjY4ODFlYzlmNWU1NzU4MDQ4ZjVhZWI0Y2M2Yzc0M2RlMDIxMTJlOTQ3OTcyZTgwMGMwMDYxYTllNTk1MWE3ZDQ0MDcyMTg5ZThmNTk1MTRmOWU5M2MzYjMxOTIwYjg0YmE5NDg0MDk1MGEyODA5NjAxN2VhOGRlNDRjMDRjOGQwOWYwMDZiMjMzYTJkMmJhZDM1NGI3Mjk0NjM5NzRkYzg5ZDdjMDVlNzgwMDVlYiIsImV4cCI6IjE2ODc3NTg3MzIiLCJ1c3NhdCI6IjM2MTFiNjI2NGUzYWQxNmJhMDIzNDhjYTBhMWU2MzdjLnVhLWVkNDM3MDk2ODk0NDg4YjI4ODcwMmZjOGM4ZDVmMzZkLjE2ODc3NTg3MzIifQ.o1X07prYaMq-pFAx0psOaIPnaLvLK-Fs4vbaSQeQI1mCfbbQv7_KgKgQ9Zqqm-wAiYa8o_ImDdkmCV6zWjsfbVKsHp_ggZp6zuSsX8ZHSVxbGLAg0jtzJYty5vPguX4aM2hihOZ1QlZldkiVVxjjUBnkEjYmR5U68rsYt4HOhHmmQ9cEw8avTfsIbKhQ3hrlJhExctHjBrqSXf8VPnVNQhxHdb3W6VhyibNBwdDtHjSGelRQKt5yJMMWErNtF78HKRrJOWTGHRD3TA_XVhSQ1mb6id8npIWdKJkBgLXjdq0jMI9ec9XSV703NOty69hm4gpUsC1P3G6cuthWW4hu_Q; Path=/; Domain=rozetka.com.ua; Expires=Mon, 26 Jun 2023 05:52:12 GMT; HttpOnly; Secure ussapp=6iNPAN-mxBUnsp2XUHjA_CpFGi0u_eu8h8fMF94W; Path=/; Domain=rozetka.com.ua; Expires=Mon, 24 Jun 2024 18:17:15 GMT; HttpOnly; Secure ussat=3611b6264e3ad16ba02348ca0a1e637c.ua-ed437096894488b288702fc8c8d5f36d.1687758732; Path=/; Domain=rozetka.com.ua; Expires=Mon, 26 Jun 2023 05:52:12 GMT; HttpOnly; Secure ussat_exp=1687758732; Path=/; Domain=rozetka.com.ua; Expires=Mon, 26 Jun 2023 05:52:12 GMT; Secure ussrt=874c688b66a830d9688c86184820f985.ua-ed437096894488b288702fc8c8d5f36d.1690307532; Path=/; Domain=rozetka.com.ua; Expires=Tue, 25 Jul 2023 17:52:12 GMT; HttpOnly; Secure; _uss-csrf=tzgUN0bNTLDwD/ZKhKraF9AKBVvaOq2xUpnyVRgshtGo9Reh; ussajwt=eyJhbGciOiJSUzI1NiIsImtpZCI6InVzc2F0LnYwIiwidHlwIjoiSldUIn0.eyJkZXRhaWxzIjoiNzYwYmUzZmNhMDA5ZDFmODhlM2ZhZWE5Mzk5OTcxZWJjZjU1YTI1MTQwZWMwZmQxNWJlYTJmOTcwNTZlMDNkZTRlMzBmOWE4NDE4Yjg5OTE1YzIyZTFiMGMwYzMwMWUyMGQyYzg4NTI4YTA4N2YxNTZiNTlmMTk1ODMxMWYyOWQ2MjY0Mzk3ZGM2ZjBjYjYyZWUxOTZjZDZhYjg0Y2EyZDBhNTM3YTQ5ZjE1Y2MwYjk0N2NhMGZkODU5MThhYTA5MzdhMWI3ZDk0YWZhZDUyMjZhZWUzMDA2OTZjOGQ0MzcwODE2MTMzZjEwY2Q5Y2ZlODczYTkzNjE3OWUyMGU5ZCIsImV4cCI6IjE2ODc3NTk5NjMiLCJ1c3NhdCI6ImNiOWI3NjQ3ZmViZGU1M2QxNDU1ODA4NzZlYWViMjkzLnVhLTcwZDI0NTVkZjE4MjhkYzA3M2UwYzliMGY4ZDcyOWM0LjE2ODc3NTk5NjMifQ.xcemhFUhAYc9YCeBrqzm5DYSkl8MnuSUXGvnwQsBxp7XZfb6tS5Pxo2bjtN9XSen5Hdmdvt5GIemvenFJFkF5O1Nv5JH_nPQqcw4Pyb4ecuvZnVm_UPQCge4LcYRohlnKR65r9QtoaxuZTEIlNUWtv3FR-GboEreK_cmnfQFbV576vQ3vaheiv_pb7RWTMxlYpWse-w3USkGqc0ANLqQcG0hGSFVrNMih1tFyXvfn_XMFMUTiL4_RvQnh4ECZbmluJ0ogjuRAU6PUPGvGC9t5oe-3MpWp-PCc_mW0RB9b6yNfUvNz1_6Z1pPtLK5-t16T98P25YMMCwEnOAxtTtjhw; ussapp=6iNPAN-mxBUnsp2XUHjA_CpFGi0u_eu8h8fMF94W; ussat=cb9b7647febde53d145580876eaeb293.ua-70d2455df1828dc073e0c9b0f8d729c4.1687759963; ussat_exp=1687759963; ussrt=1409eb7ec30aea2f50755df312826022.ua-70d2455df1828dc073e0c9b0f8d729c4.1690308763'
}

for pr_id in product_ids:
    payload = json.dumps([
        {
        "purchase_id": pr_id,
        "quantity": 1
        },
    ])
    response = requests.request("POST", url, headers=headers, data=payload, timeout=10)
    print(response.text)
