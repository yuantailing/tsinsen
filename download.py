import json
import pathlib
import requests

dst = pathlib.Path('data')
dst.mkdir(parents=True, exist_ok=True)
(dst/'pages').mkdir(exist_ok=True)
(dst/'submissions').mkdir(exist_ok=True)
(dst/'problems').mkdir(exist_ok=True)

cookies = {'JSESSIONID': 'xxx'}
url1 = 'http://tsinsen.com/test.SelectResults.dt'
url2 = 'http://tsinsen.com/test.GetCode.dt'
url3 = 'http://tsinsen.com/web.RequireTempFile.do'
url4 = 'http://tsinsen.com/problem.Problem.dt'

req = requests.post(
    url1, cookies=cookies,
    data={'page': 0, 'type': 'u', 'userid': -1})

pagecnt = req.json()['pagecnt']
saved_gpid = set()

for page in range(1, pagecnt + 1):
    req = requests.post(
        url1, cookies=cookies,
        data={'page': page, 'type': 'u', 'userid': -1})
    with (dst/'pages'/f'{page}.json').open('wb') as f:
        f.write(req.content)
    for key, submission in req.json().items():
        if not key.isdigit():
            continue
        print(submission)
        sid = submission['id']
        gpid = submission.get('gpid')
        lang = submission['lang']
        with (dst/'submissions'/f'{sid}.json').open('w', encoding='utf-8') as f:
            json.dump(submission, f, ensure_ascii=False, indent=2, sort_keys=True)
        req = requests.post(
            url2, cookies=cookies,
            data={'submitid': sid, 'cmd': 'download'})
        handle = req.json()['handle']
        req = requests.post(
            url3, cookies=cookies,
            data={'handle': handle})
        with (dst/'submissions'/f'{sid}.{lang.lower()}').open('wb') as f:
            f.write(req.content)
        if gpid is not None and gpid not in saved_gpid:
            req = requests.post(
                url4, cookies=cookies,
                data={'cmd': 'description', 'gpid': gpid})
            with (dst/'problems'/f'{gpid}.json').open('wb') as f:
                f.write(req.content)
            saved_gpid.add(gpid)
