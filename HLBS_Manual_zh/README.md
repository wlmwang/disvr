# 导读

| 版本 | 日期 | 说明 | 修订 | 审核 |
| -- | -- | -- | -- | -- |
| 1.1.0 | 16/04/21 | release | ~ | ~ |


## 文档约定

* Svr：配置(svr.xml)在HLBS系统中的后端服务。即为“被调”的服务。

* CGI：通过HLBS系统获取具体Svr来使用的前端业务。相对Svr属于消费者。

* Qos：服务质量。标识各Svr负载大小、服务能力。可简单理解成配置（qos.xml）在HLBS系统中周期大小、比例因子、阈值控制以及Svr实时统计互相作用的一套容错体系。