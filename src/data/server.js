const http = require("http");

const server = http.createServer((req, res) => {
  res.setHeader("Access-Control-Allow-Origin", "*");
  if (req.url === "/temp") {
    res.writeHead(200, { "Content-Type": "text/plain" });
    res.end("26.4");
  } else {
    res.writeHead(404, { "Content-Type": "text/plain" });
    res.end("Ruta no encontrada");
  }
});

server.listen(192, () => {
  console.log("Servidor en http://localhost:192/temp");
});
