// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "ʯ��");
    set("long", @LONG
����һ����ɭ�ĵ�·��������һ������ٸ�ӣ����������ĺ��ǣ�
������ʼ�ʽ���������Ĺ�󣬰�ȫ����ʩ���߶�ɱ���������ˣ�����
������ɭɭ�׹�,��������Щ�����Ź�.��ֻ�����е�ë���Ȼ��  
LONG
);
        set("exits", ([
           "south":__DIR__"shidao4",
           "north":__DIR__"outroom",
           "west":__DIR__"clubroom",
           "east":__DIR__"axeroom",
]));
        set("objects", ([
             __DIR__"obj/skeleton" : 1+random(10),
]));
    setup();
}
void init()
{
add_action("do_search","search");
//  add_action("do_train","rain");	
}
int do_search(string arg)
{
object me=this_player();
object ob; 
if( (!arg) ||!((arg == "bone") || (arg == "�Ź�")))
return notify_fail("��Ҫ����ʲô��\n");
if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="staff" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword" ) )
return notify_fail("û�й�����ô�ɻ\n");
message_vision(HIR "\n$N���Ღ�����°׹ǡ�\n\n" NOR, me);	
if(query("not_jianpu")) {
message("vission", HIR "ֻ������һ����������ܳ�����ֻ������\n"NOR, me);	
return 1;
}
ob=new("/clone/book/wuming.c");
ob->move(me);	
me->set("qinhuang",1);
message_vision(HIR "ֻ��������..��һ�������������һ��"HIM+"�Ͼ��ؼ�"+NOR"��\n\n\n"NOR, me);    	
set("not_jianpu", 1);
call_out("regenerate", 86400);
return 1;
}
int regenerate()
{
set("not_jianpu", 0);
return 1;
}
