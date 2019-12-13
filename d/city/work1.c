
inherit "/inherit/room/work";

void create()
{
	set("short", "谷物加工厂");
	set("long", @LONG
这是一间谷物加工厂，这里是谷子脱壳成米的地方。米厂老板是一
个一看就知道是十分精明的干瘦的中年人，老是带着一脸奸笑。你可以
看到许多人正在忙忙碌碌的工作着，门口挂著一块牌子(sign)。
LONG );
	set("no_sleep_room",1);
	set("no_fight",1);	
	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"ximen",
	]));
	set("item_desc", ([
		"sign": @TEXT
现在正紧缺人手，急需雇佣一批短工来干活。
work     开始工作。
TEXT]) );
	set("no_magic", 1);
	set_heart_beat(5+random(get_system_config(DATA_CONFIG_DIR "work.h", "do_heart_times")));
	setup();
}
