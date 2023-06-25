'''this code is for clicking https://www.demoblaze.com/ site'''

import time
from selenium import webdriver

from selenium.webdriver.common.by import By

linka = "https://www.demoblaze.com/"
browser = webdriver.Chrome()

options = webdriver.ChromeOptions()
options.add_experimental_option("detach", True)
options.add_argument('--keep-alive')
browser = webdriver.Chrome(options=options)

browser.get(linka)
time.sleep(5)

verif = browser.find_element(By.XPATH, '//*[@id="itemc"]').text
print(verif)
time.sleep(2)
contacts_btn = browser.find_element(By.XPATH, '//*[@id="navbarExample"]/ul/li[2]/a')
contacts_btn.click()
email_fld = browser.find_element(By.XPATH, '//*[@id="recipient-email"]')
email_fld.send_keys = "12345@asd.com" 
time.sleep(2)
name_fld = browser.find_element(By.XPATH, '//*[@id="recipient-name"]')
name_fld.send_keys = "Ivanoff"
time.sleep(2)
msg_fld = browser.find_element(By.XPATH, '//*[@id="message-text"]')
msg_fld.send_keys = "Hello there!"
time.sleep(2)
snd_msg_btn = browser.find_element(By.XPATH, '//*[@id="exampleModal"]/div/div/div[3]/button[2]')
snd_msg_btn.click()

 
time.sleep(200) 
browser.find_element(By.XPATH, "//a[contains(text(),'Установка')]")
browser.find_element(By.XPATH, "//h2[contains(text(),'Содержание:')]")
browser.find_element(By.XPATH, "/html[1]/body[1]/div[1]/div[1]/div[2]/main[1]/div[1]/div[1]/div[1]/div[1]/div[1]/div[2]/div[1]/div[1]/div[1]/article[1]/div[2]/div[2]/div[1]/div[1]/div[1]/br[2]")
browser.find_element(By.XPATH, "//div[@id='post-content-body']")
browser.find_element(By.XPATH, "//body/div[@id='app']/div[1]/div[2]/main[1]/div[1]/div[1]/div[1]/div[1]/div[1]/div[2]/div[1]/div[1]/div[1]/article[1]/div[2]/div[2]/div[1]/div[1]")
browser.find_element(By.XPATH, "//body/div[@id='app']/div[1]/div[2]/main[1]/div[1]/div[1]/div[1]/div[1]/div[1]/div[2]/div[1]/div[1]/div[1]/article[1]/div[2]/div[2]/div[1]/div[1]/div[1]")
browser.find_element(By.XPATH, "/html[1]/body[1]/div[1]/div[1]/div[2]/main[1]/div[1]/div[1]/div[1]/div[1]/div[1]/div[2]/div[1]/div[1]/div[1]/article[1]/div[2]/div[2]/div[1]")