// Room: /d/dali/qianzhuang.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月21日，北京时间：17时37分25秒。

inherit ROOM;

void create()
{
	set("short", "钱庄");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发
行的银票信誉非常好，通行全国。帐台上有一个牌子（ｓｉｇｎ）。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qian.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dbdajie1",
]));

        set("item_desc", ([
                "sign": @TEXT
这里是钱庄，目前我们提供的服务有：
convert(huan)     兑换钱币。
deposit(cun)      存钱。
withdraw(qu)      取钱。
check(cha)        查询存款。
TEXT
        ]) );

  set("no_fight",1);
	setup();
}
