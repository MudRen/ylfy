// music yangzhou's ѩ��
#include <ansi.h>

inherit ITEM;
int count=10;
void create()
{
        set_name(HIC"������Ѫ��"NOR, ({ "yu","biyu","qinglong" }) );
        set("long", "һ�����,������Ȼ�γ�һ��ѩ��ķ�����
�������(use yu)���ָ������ֵ,����ֻ��ʹ��10��.
��������,����Ը�.\n");
        set("unit", "��");
        set("weight", 100);
        set("money_id",1);
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("��Ҫʹ��ʲ�᣿\n");
if( living(this_player()) ==0 ) return 0;
        ob=this_player();
        if (count==0) {
 message_vision("$N���е�$nͻȻ����һ������,��ը��.\n",ob,this_object());
 ob->die();
 destruct(this_object());
 return 1;
                 }
        ob->set("kee",(int)ob->query("max_kee"));
        ob->set("gin",(int)ob->query("max_gin"));
        ob->set("sen",(int)ob->query("max_sen"));
        ob->set("eff_kee",(int)ob->query("max_kee"));
        ob->set("eff_gin",(int)ob->query("max_gin"));
        ob->set("eff_sen",(int)ob->query("max_sen"));

        ob->set("force", (int)ob->query("max_force"));
        ob->set("food",((int)ob->query("str")-10)*10+200);
        ob->set("water",((int)ob->query("str")-10)*10+200);
        ob->set_temp("windnod",1);
        write("[1;33m�����еı��񷢳�ѩ��Ĺ�ã��\n[0;37m");
        message("vision", HIY + ob->name() + 
"���еı��񷢳�ѩ��Ĺ�,һ��������\n"+NOR,
                environment(ob), ob);
     count--;
        return 1;
}
int move(mixed dest)
{
        if(! userp(dest))       return ::move(dest);
        if( ::move(dest)==0)    return 0;
        message("channel:rumor",YEL"���������š�"+ "ĳ�ˣ�������Ѫ��"+
        dest->query("name")+"�õ��ˣ�\n"NOR,users());
        return 1;
}
