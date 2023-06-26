import json
import requests


url = "https://uss.rozetka.com.ua/session/cart-se/add"
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
  'Cookie': 'cart-modal=old; ab-auto-portal=old; promo-horizontal-filters=verticalFilters; ab-catalog-tile-description=old; ab-catalog-filter-result-quantity=old; social-auth=old; ab_tile_filter=old; xab_tests=%7B%22ab-catalog-backend%22%3A%22new%22%2C%22cart-modal%22%3A%22old%22%2C%22ab-auto-portal%22%3A%22old%22%2C%22filter-tabs%22%3A%22old%22%2C%22ab-catalog-delivery-terms%22%3A%22old%22%2C%22ab-catalog-selection-filters%22%3A%22old%22%2C%22promo-horizontal-filters%22%3A%22verticalFilters%22%2C%22ab-catalog-tile-description%22%3A%22old%22%2C%22ab-catalog-filter-result-quantity%22%3A%22old%22%2C%22fingerprint%22%3A%22on%22%2C%22skip-add-phone%22%3A%22off%22%2C%22social-auth%22%3A%22old%22%2C%22ab-ch-contact-form%22%3A%22new%22%2C%22ab_ch_seller_btn%22%3A%22off%22%2C%22ab_tile_filter%22%3A%22old%22%2C%22ab_hotjar%22%3A%22on%22%7D; xab_segment=6; slang=ru; uid=Cgo8kGSWkPB/5k8WiKhqAg==; visitor_city=1; _uss-csrf=feuKF63pCE3yW/aEZjhfyZHf2l7rHi/qoYGjNl0Q8m6HHOxG; ussapp=6iNPAN-mxBUnsp2XUHjA_CpFGi0u_eu8h8fMF94W; rz_ch_mo=off; rz_ch_rtfnp=on; rz_ch_cp=on; ussrt=68687fb9f4131b8ff05d67cf9646e5f7.ua-ed437096894488b288702fc8c8d5f36d.1690263042; ussat_exp=1687714242; ussajwt=eyJhbGciOiJSUzI1NiIsImtpZCI6InVzc2F0LnYwIiwidHlwIjoiSldUIn0.eyJkZXRhaWxzIjoiNGU2YjcxNGFiNTY3ZjY2YWM3YmUxYjI1NmJlYTg1MzZjODJhMDEwY2EzOGM1MWQ2OTY5NmMzYzU3ZWUyYTA4YmI2Mjg3MGIxMThkYjg4NWIyYzBkZWNjMDA1MzJmNWNlMzJkMmNhOGE0ZmJmNGEyMzA4ZGVjYmU2ZTM4YjVjZjg2MDNhMDIxZjJlNzE5NTRkOGRiMmQ0OGI4MTRhNGUwNDYxNmUxOTg1ZDQ5MTVhNjZlZGRjODZlNjRkYjNiM2E0OTVhOWMxMGQ3ZjMyNWU0ZDUzNzFmZWI1YTU2NDI1ODVkNGYwNjVkY2NjNGRlOGZhY2VkOTZhOGU4YTU0NDgzYyIsImV4cCI6IjE2ODc3MTQyNDIiLCJ1c3NhdCI6ImI4NDE3NWRjNTUwNzE5YTMxMDkyNmY3MDM4NTNlOTBjLnVhLWVkNDM3MDk2ODk0NDg4YjI4ODcwMmZjOGM4ZDVmMzZkLjE2ODc3MTQyNDIifQ.dNhDneuXfN5mbBMZOjYW5fShjouphlLxfs1i0yMXVTBH8Z_ychpIkSqhBDNUVa61cu30-WilOaD6eFGagjievZXnfUEstOCbzdDHcQMZvgUlwCMnTzPprKHGV2jLD3dJFcka6i-OiwxxumTXr7q1iWEdwTZmUxT6peAu9GPPXdWHa71kOXgrKopOkJZzOKgyBDPZ8QvicMoxiiR007ny1PGSONgnlPWrJI3vZHd6nLBgZns2ncPBBoLs4urGda2SzFtSsyr7TrOlN_9oIUnx7h6Z6UAvTU5jkHH5p2xwIthhnUoNZe6wesnQQM3IbUUo_H6HgF-U3kLo-3zRvMenYw; ussat=b84175dc550719a310926f703853e90c.ua-ed437096894488b288702fc8c8d5f36d.1687714242; __cf_bm=Fdt57gIGI2akj6.a8ezexi8nyyzPyTHnrF3GNCCj88g-1687697196-0-Ab3wdNfs67axwp0u9Bpr8QFAyXzLVPEYMqqTDtFHOvW8u2bqkcroT5ivUh0GMPHjTU2G5Ofh2nJw24K5O0ouBww=; _uss-csrf=tzgUN0bNTLDwD/ZKhKraF9AKBVvaOq2xUpnyVRgshtGo9Reh; ussajwt=eyJhbGciOiJSUzI1NiIsImtpZCI6InVzc2F0LnYwIiwidHlwIjoiSldUIn0.eyJkZXRhaWxzIjoiNGU2YjcxNGFiNTY3ZjY2YWM3YmUxYjI1NmJlYTg1MzZjODJhMDEwY2EzOGM1MWQ2OTY5NmMzYzU3ZWUyYTA4YmI2Mjg3MGIxMThkYjg4NWIyYzBkZWNjMDA1MzJmNWNlMzJkMmNhOGE0ZmJmNGEyMzA4ZGVjYmU2ZTM4YjVjZjg2MDNhMDIxZjJlNzE5NTRkOGRiMmQ0OGI4MTRhNGUwNDYxNmUxOTg1ZDQ5MTVhNjZlZGRjODZlNjRkYjNiM2E0OTVhOWMxMGQ3ZjMyNWU0ZDUzNzFmZWI1YTU2NDI1ODVkNGYwNjVkY2NjNGRlOGZhY2VkOTZhOGU4YTU0NDgzYyIsImV4cCI6IjE2ODc3MTQyNDIiLCJ1c3NhdCI6ImI4NDE3NWRjNTUwNzE5YTMxMDkyNmY3MDM4NTNlOTBjLnVhLWVkNDM3MDk2ODk0NDg4YjI4ODcwMmZjOGM4ZDVmMzZkLjE2ODc3MTQyNDIifQ.dNhDneuXfN5mbBMZOjYW5fShjouphlLxfs1i0yMXVTBH8Z_ychpIkSqhBDNUVa61cu30-WilOaD6eFGagjievZXnfUEstOCbzdDHcQMZvgUlwCMnTzPprKHGV2jLD3dJFcka6i-OiwxxumTXr7q1iWEdwTZmUxT6peAu9GPPXdWHa71kOXgrKopOkJZzOKgyBDPZ8QvicMoxiiR007ny1PGSONgnlPWrJI3vZHd6nLBgZns2ncPBBoLs4urGda2SzFtSsyr7TrOlN_9oIUnx7h6Z6UAvTU5jkHH5p2xwIthhnUoNZe6wesnQQM3IbUUo_H6HgF-U3kLo-3zRvMenYw; ussapp=6iNPAN-mxBUnsp2XUHjA_CpFGi0u_eu8h8fMF94W; ussat=b84175dc550719a310926f703853e90c.ua-ed437096894488b288702fc8c8d5f36d.1687714242; ussat_exp=1687714242; ussrt=68687fb9f4131b8ff05d67cf9646e5f7.ua-ed437096894488b288702fc8c8d5f36d.1690263042'
}


for pr_id in product_ids:
    payload = json.dumps([
        {
        "goods_id": pr_id,
        "quantity": 1
        },
    ])
    response = requests.request("POST", url, headers=headers, data=payload, timeout=10)
    print(response.text)
