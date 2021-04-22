from GoogleNews import GoogleNews
googlenews=GoogleNews(lang='en', period='7d', encode='utf-8')
googlenews.search("Asian American")
googlenews.get_page(3)
r=googlenews.results(sort=True)
for item in r:
    print(item['title'])
    print(item['link'])

