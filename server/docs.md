# Newgrounds Proxy Self-Hosting
I'm very happy you're here.

## Requirements
If you do not have any of these requirements, you can not proceed with this tutorial.
- Cloudflare account
- Domain
- Linux sever (perferably Ubuntu 20.04 on [Linode](https://linode.com))
- Basic domain and nameserver knowledge

## Installation
1. SSH into your server as root and install the dependencies using the following command
```sudo apt install certbot nginx python3-certbot-nginx```
2. Change the configuration file to your liking and put the file into `/etc/nginx/sites-available/default`
3. Install a SSL certificate using `sudo certbot --nginx`
4. Open up your Cloudflare Dashboard and setup your domain with Cloudflare.
5. Install the Client GD Mod and change the server URL in the config to your domain.