#Usage: py google_scrap.py out.csv

from GoogleNews import GoogleNews
import sys
googlenews=GoogleNews(lang='en', period='7d', encode='utf-8')
googlenews.search("Asian American")
for i in range(2, 11):
    googlenews.get_page(i)
r=googlenews.results(sort=True)
print(len(r))

fn=sys.argv[1]
output=open(fn, "w")
for item in r:
    print("\""+item['date']+"\",=HYPERLINK(\""+item['link']+"\"),\""+item['title']+"\",\""+item['media']+"\",\""+item['desc']+"\"", file=output)
output.close()

