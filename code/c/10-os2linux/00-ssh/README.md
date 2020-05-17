# SSH

## ssh client

在 powershell 中打 ssh 看看反應如何

若已經有 ssh, 則可以直接用 ssh guest@misavo.com 連進老師的伺服器。

若沒有，可以先安裝 putty 後啟動再連進去。

```
PS D:\ccc\course\sp\code\c> ssh
usage: ssh [-46AaCfGgKkMNnqsTtVvXxYy] [-B bind_interface]
           [-b bind_address] [-c cipher_spec] [-D [bind_address:]port]
           [-E log_file] [-e escape_char] [-F configfile] [-I pkcs11]
           [-i identity_file] [-J [user@]host[:port]] [-L address]
           [-l login_name] [-m mac_spec] [-O ctl_cmd] [-o option] [-p port]
           [-Q query_option] [-R address] [-S ctl_path] [-W host:port]
           [-w local_tun[:remote_tun]] destination [command]
PS D:\ccc\course\sp\code\c> ssh guest@misavo.com

guest@localhost:~$ ls
ai  git  sp  spMore  wp
guest@localhost:~$ cd sp
guest@localhost:~/sp$ ls
code  _config.yml  course.md  docs  LICENSE  README.md
```

## vscode

安裝 ssh fs 插件，可以遠端使用 vscode 編輯 server 上的檔案

1 - 先從 Extension 尋找 ssh fs 並安裝好
2 - 然後到 File/Preference/Setting 編輯 setting.json，加入以下資訊

```json
{
    "remote.onstartup": true,
    "sshfs.configs": [
        {
            "root":"/home/guest",
            "host": "misavo.com",
            "username": "guest",
            "password": "csienqu",
            "name": "guest"
        }
    ]
}
```

3 - 按下 F1 輸入 ssh fs 選 SSH FS:Connect as Workspace Folder 

然後會看到 Explorer 中出現 SSH FS-guest 的資料夾

裡面有 sp 這個子資料夾，於是你可以用 vscode 直接修改檔案。


