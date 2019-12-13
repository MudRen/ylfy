inherit ROOM;
void create()
{
        set("short", "云雨舟大厅");
        set("long", @LONG
红木舱板被擦的纹理并现。墙壁四周挂满了当地名人的书词提画。厅中一张大红
地毯，足有五丈方圆。几个纱衣朦胧的妙龄少女正在随歌而舞。有到话：
[1;31m
                        绛衣披拂露盈盈，
                        淡染胭脂一朵轻。
[2;37;0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"boat3",
  "south" : __DIR__"wting",
  "north" : __DIR__"eting",
  "westup"   : __DIR__"stairs",
]));

       set("objects", ([
        __DIR__"npc/dancer" : 3,
                        ]) );

        setup();
}
