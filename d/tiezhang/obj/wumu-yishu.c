// wumu-yishu.c
#include <ansi.h>

inherit ITEM;
void setup()	
{}
void init()
{
if (this_player()==environment()){	
add_action("do_du", "du");	
add_action("do_du", "study");	
}
}

void create()
{
	set_name( "���������项", ({ "wumu yishu", "yishu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			GRN
			"\n���������������ǰ���µġ��ƽ�Ҫ������\n"
			"ֻ����һҳ��д��ʮ�˸����֣�\n"
                        "������ѡ����ѵϰ��\n"
                        "�����ͷ��������\n"
                        "���ϼ�  ��ͬ�ʿࡱ\n"
               NOR
		);
		set("value", 10000000);
		set("material", "paper");
		set("no_get", 1);
		set("no_drop", 1);
		set("treasure", 1);
	}
}

int do_du(string arg)	
{
object me = this_player();	
object where = environment(me);		
        
if (!(arg=="wumu yishu" || arg == "yishu"))	
return 0;	
if (where->query("pigging")){	
write("�㻹��ר�Ĺ���ɣ�\n");	
return 1;	
}
if (me->is_busy()) {	
write("��������æ���ء�\n");	
return 1;	
}
if( me->is_fighting() ) {	
write("���޷���ս����ר�������ж���֪��\n");	
return 1;	
}
if (!id(arg)) {		
write("��Ҫ��ʲô��\n");	
return 1;	
}
if( !me->query_skill("literate", 1) ){	
write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");	
return 1;	
}

if (me->query("mark/+int")) 	
        {
        write("�������һ����������ѽ������\n");
return 1;	
        }
message("vision", me->name() + HIY"���ַ����������飬����һ��һ��֮�䣬�޲���������Եе��������������̾��\n"NOR,environment(me), me);
me->add("int", 1);	
        write(HIR"�����������ˣ�\n"NOR);
me->set("mark/+int", 1); 	
destruct(this_object());	
        return 1;
}
