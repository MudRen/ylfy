#include <weapon.h>

inherit SWORD;
#include <ansi.h>

void create()
{
   set_name(HIC"���ǽ�"NOR, ({ "qixing sword", "jian", "sword" }) );
   set_weight(8000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("icon", "10084");
     set("value", 10000);
     set("material", "steel");
     set("long", "����һ�ѷ������ٽ𽣣����滭����������ǣ������Ի�����ǽ��������������˵��彣��\n");
     set("wield_msg", "һ�����������$N�����Ѷ��˰�$n��\n");
     set("unequip_msg", "$N�������е�$n��\n");
   }
init_sword(400,2);	
   setup();
}
void init()
{
if(this_player()!=environment())
add_action("do_get","get");
}
int do_get(string arg)
{
object me=this_player();
object ob=this_object();
string place;
if(environment(ob)->query("short"))
place = environment(ob)->query("short");
else place = "һ����Ϊ��֪�ĵط�";
if(arg=="qixing sword"){                  	
if(ob->move(me))
message("rumor",HIW"\n���������š�����˵"+me->name()+"��"+place+"Ū����һ��"HIC"���ǽ�\n\n"NOR,users());
me->add("jing",-(me->query("max_jing")/3));
me->set("neili",0);
return 1;
}
return 0;
}
int query_autoload() { return 1; }	
