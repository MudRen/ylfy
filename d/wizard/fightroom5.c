// Room: /d/wizard/fightroom5.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "柳莺湖");
    set("long", @LONG
这是个不大不小的湖泊，湖边树木成阴，黄莺的叽喳声从林间传出。微风吹
过，清凉宜人。湖水呈深蓝色，湖面虽不大，可湖水却深不可测。湖边还有几株
垂柳，柳树把它们的柳丝垂到了溪面上微风佛过，在平静的溪面上画著圈圈点点，
逗的水中的鱼儿不停地跃出水面。几只羽毛艳丽的鸳鸯在水面上荡来荡去，不时
地把头探入水中寻找它们的食物，还有几只在岸边休息。
LONG
    );
    set("no_new_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/city/zuixianlou",
  "east" : __DIR__"fightroom4",
]));
    setup();
    replace_program(ROOM);
}
