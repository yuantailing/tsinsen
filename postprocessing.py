import datetime
import html
import json
import os
import pathlib
import pytz
import shutil
import time

from collections import defaultdict

src = pathlib.Path('data')
dst = pathlib.Path('problems')
dst.mkdir(parents=True, exist_ok=True)

gpid2sid = defaultdict(list)
sid2data = dict()
sid2path = dict()

for filepath in (src/'submissions').iterdir():
    sid, ext = int(filepath.stem), filepath.suffix
    if ext == '.json':
        with filepath.open(encoding='utf-8') as f:
            data = json.load(f)
        if 'gpid' in data:
            gpid2sid[data['gpid']].append(sid)
            sid2data[sid] = data
    else:
        sid2path[sid] = filepath

for gpid, sids in sorted(gpid2sid.items()):
    (dst/gpid).mkdir(exist_ok=True)
    with (src/'problems'/f'{gpid}.json').open('rb') as f:
        data = json.load(f)
    with (dst/gpid/'index.html').open('w', encoding='utf-8') as f:
        if 'content' not in data:
            continue
        f.write(f'<div>{html.escape(data["title"])}</div>\n')
        f.write(f'<div>时间限制：{html.escape(data["timelimit"])} 内存限制：{html.escape(data["memorylimit"])}</div>\n')
        f.write(data['content'])
        f.write(f'<div>编译语言：{html.escape(data["langs"])}</div>\n')
    for sid in sids:
        old_path = sid2path[sid]
        data = sid2data[sid]
        score = int(data['score'])
        submit_time = datetime.datetime(*time.strptime(data['submit'], '%Y-%m-%d %H:%M')[:6], 0, pytz.timezone('Asia/Shanghai'))
        new_path = dst/gpid/f'{old_path.stem}.{score}{old_path.suffix}'
        shutil.copy(old_path, new_path)
        os.utime(new_path, (new_path.stat().st_ctime, submit_time.timestamp()))
