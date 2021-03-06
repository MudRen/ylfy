
inherit ROOM;
#define DA_EXP 3000+random(3000)

void create()
{
    set("short", "树林");
    set("long", @LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼天
大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出的声响。
这正是个打鸟（da）的好机会。
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
	"/d/mengpai/xydizi" : 3,
      ]));
    set("outdoors", "xiaoyao");
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"xiaodao4",
	"north" : __DIR__"shulin1",
	"east" : __DIR__"shulin2",
	"south" : __DIR__"shulin1",
      ]));
    set("no_clean_up", 0);
    set("no_msg_vision",1);

    setup();
    //replace_program(ROOM);
}

void init()
{
    add_action("do_da", "da");
}

int do_da()
{
    object me;
    string *name, *color, get_name;
    int val, max, exp, pot, flag;

    me = this_player();
    name = ({ "麻雀", "山鸡", "喜鹊", "乌鸦", "杜鹃", "鹦鹉", "画眉鸟", "黄莺", "百灵鸟", "金丝雀" });
    color = ({ RED, GRN, YEL, BLU, MAG, CYN, WHT, HIR, HIG, HIY, HIB, HIM, HIC, HIW });

    if ( !me ) return 0;
    if ( me->is_busy() ) return notify_fail("你还是等弓装好了箭再打鸟吧！\n");
    if ( me->query("qi") < 10 ) return notify_fail(HIY"你还是先休息一下吧，射箭也要用力气哟。\n"NOR);
    if ( me->query("xyzx_sys/level") >= 100 )
	return notify_fail(HIR"你已经不能通过打鸟来进行磨练了，可以去试试运镖。\n"NOR);

    me->start_busy(1);
    me->receive_damage("qi", 10);
    tell_object(me,"你拿起儿时玩耍用的小弓小箭，瞄准树上的小雀射去......\n");
    tell_object(me,"你只听树上一阵鸟儿急鸣…\n");
    max = sizeof(name);
    val = random(max);
    exp = DA_EXP;
    pot = exp/10;
    flag = random(sizeof(color));

    if ( random(100) > 98 ) 
	tell_object(me,"你什么也没打到。\n");
    else
    {
	get_name = color[flag]+name[val];
	me->add("combat_exp", exp, 1);
	me->add("potential", pot, 1);
	tell_object(me,"你打到一只"+get_name+"。\n"NOR);
	tell_object(me, "你得到了"HIM+(exp*me->query_exp_times())+NOR"点经验。\n");
	tell_object(me, "你得到了"HIY+pot+NOR"点潜能。\n");

    }

    return 1;
}
