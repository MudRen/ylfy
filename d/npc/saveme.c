//wizer.c
#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;
 
void create()
{

           set_name("��ħ��ʿ--��ޱ˿", ({ "wizer", "w","wiz" }) );
set("age", 3500);	
           set("long",@STORY
һ����������,������ɴ��������ò������Ů��,��˵���Ѿ�������	
ǧ�������,���Ҵ�û���˼�����������Ŀ,����ɴ֮�µ���׾���
�������??����������������,����ʹ??����ħ��??
��֪�ι�,�ڶ���ǰ�����������̶,���ʹ˶���������,����������	
ȫ����������֪��,��������ʲܡ��ʹ,ֻҪ������(saveme),���ͻ�	
����ҽ��,Ҫ�ǵö�������!!
STORY
              );
           set("chat_chance", 15);
          // exert_function(10);
	   set("chat_msg", ({
	    "��ħ��ʿ--��ޱ˿�����۾�ڤ˼��\n",
	    "��ħ��ʿ--��ޱ˿˵��:��˯��ʱ���е���������....\n",
            "��ħ��ʿ--��ޱ˿˵��:���ڽ����������Ĵ���Ů�������....\n",
            "��ħ��ʿ--��ޱ˿˵��:�������кڰ�,�޴���һ��...,ƽ�ȵػ����!!...\n",
	    }));

        set("gender","Ů��");
set("combat_exp",15000000);	
set("max_neili", 1500);	
set("neili", 1500000);	
set("jingli", 1500000);	
set("max_jingli", 1500);	
set("max_qi", 150000);              	
set("max_jing", 350000);    	
set("jiali", 1500);	
        set("force",9999999);
set_skill("unarmed", 999);       	
set_skill("dodge", 999);       	
set_skill("kuihua-xinfa", 999);        	
set_skill("parry", 999);       	
set_skill("sword", 999);        	
set_skill("pixie-jian", 520);        	
set_skill("king-of-dragon", 999);	
        set_skill("force",999);
map_skill("force", "kuihua-xinfa");   	
map_skill("dodge", "pixie-jian");   	
map_skill("parry", "pixie-jian");   	
map_skill("sword", "pixie-jian");   	
map_skill("unarmed", "king-of-dragon");	
set("chat_chance", 350);                  
set("chat_msg", ({	
(: command, "exert sneaky" :),       
}) );	


	setup();
carry_object("clone/cloth/qiankun")->wear();		
carry_object("clone/weapon/longyin")->wield();            	
}

void init()
{
	add_action("do_save_me", "saveme");
}

int do_save_me(object ob, string arg)
{
           ob=this_player();     
if( ob->is_busy() )	
return notify_fail("����һ��������δ���,����ʩ�÷�����̫�ð�!\n");    	
if( ob->is_fighting() )	
return notify_fail("ս����Ҳ������ʩ�÷�������ָ�?�����������ΪŶ!\n");        	
else {	
	   ob->set("jing",ob->query("max_jing") );
	   ob->set("qi",ob->query("max_qi") );
	   ob->set("eff_qi",ob->query("max_qi") );
	   ob->set("food", (int)ob->max_food_capacity() );
          ob->set("water", (int)ob->max_water_capacity() );
ob->start_busy(15);	
message_vision(HIY"��ħ��ʿ--��ޱ˿���������: ����ˮ��Ů�������...����������˵��˻ظ���!!\n"NOR,ob);	
message_vision(ob->query("name")+HIW"ͻȻ��һ�������У�����ȫ�����������\n"NOR,ob);                       	
	        return 1;    
	     	
}
}	





