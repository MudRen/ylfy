//baiyuan.c 
#include <ansi.h> 
inherit NPC;

void create()
{
        set_name(HIW"��Գ"NOR, ({ "bai yuan","yuan" }) );
        set("gender", "����" );
        set("age", 16);
        set("str", 25);
        set("int", 16);
        set("con", 25);
        set("dex",25);  
        set("long", @LONGһֻͨ���ë�Ĵ�Գ��,��������ͨ���⡣
LONG
);
        set("attitude", "peaceful");
        set("combat_exp", 50000);

        set_skill("unarmed", 60);
        set_skill("force",40);
        set_skill("jiuyang-shengong",20);  
        set_skill("dodge", 80);
        map_skill("force","jiuyang-shengong");
        map_skill("unarmed","jiuyang-shengong");
        set("env/wimpy", 50);           
        set("chat_chance", 10);
        set("chat_msg", ({
                HIR"��Գ����գ��գ�۾�������������Ҫʳ���  \n"NOR,
        }) );
        setup();
} 
int accept_object(object me, object ob)
{
        object book;

        if( !me || environment(me) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, me) ) return notify_fail("��Գϲ���Ե��ǡ��� \n");
        if (  (string)ob->query("name") != "����")
                    return notify_fail("��Գϲ���Ե��ǡ���  \n");
                
message_vision(HIC"��Գ���˵ĳ�$N���ͷ��Ȼ�󶪸�$Nһ�����õ���Ƥ�飬ת��ĵ�һ������ʳ��ȥ�ˣ�\n"NOR, me);
book=new("/d/mingjiao/obj/jianlun");	
                           book->move(me);
                return 1;
        }


