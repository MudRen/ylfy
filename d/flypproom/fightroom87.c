// Room: /d/flypproom/fightroom87.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
        set("short", "飞天楼专用挑战广场");
    set("long", @LONG
这是一个方圆数十丈的大广场，一个用白玉汉石砌成数丈高的擂台耸立在广
场中央，从上面不时传来吆喝声和惨叫声，擂台的四个边角竖着四根十多丈高的
旗杆，分别用金线绣着风云再起四个大字，广场的正北方用同样的石料砌了一	
个小台。台上竖着一根大旗杆，一张大旗(flag)迎风招展。\n这里跟别的擂台有些不一样是,来挑战的人需要签下 "生死状",这使很多武林人士都望而生畏... ...
LONG
    );
    set("item_desc", ([
                "flag": @TEXT
              独孤求败！
TEXT
    ]) );
    set("exits", ([ /* sizeof() == 2 */
                "down" : "/d/taishan/fengchan",
                "up" : __DIR__"fightroom88",
        ]));
setup();
	replace_program(ROOM);
}

