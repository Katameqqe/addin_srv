## How to generate ssl crt

```
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout server.key -out server.crt -subj "/CN=localhost" -addext "subjectAltName=DNS:localhost"

openssl x509 -in server.crt -outform PEM -out cert.pem

openssl rsa -in server.key -out key.pem -outform PEM

```

Or for ip address
```
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout server.key -out server.crt -subj "/CN=x.x.x.x" -addext "subjectAltName=IP:x.x.x.x"
```
