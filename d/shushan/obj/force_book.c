//book by yushu 2001.2
// lilong alter 2002.01.17
inherit ITEM;
int do_read(string arg);
void create()
{
        set_name("����ɽ�ķ���", ({"shushan-force","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	  set("long",
	"����д�������������,�������ǹ�����ɽ���ش��ڹ����顣\n");
        set("material", "paper");
        set("value", 1000);
        set("skill", ([
                        "name": "shushan-force",
                        "exp_required": 1000,
                        "jing_cost": 30,
                        "difficulty": 30,
                        "max_skill": 200,
]) );
          }
}
void init()
{
    add_action("do_read", "read");
}
int do_read(string arg)
{
    object me=this_player();
    if(me->query("family/family_name")!="��ɽ��")
        return notify_fail("������ɽ�Ĳ��ܶ��Ȿ�飡\n");
}
