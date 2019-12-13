//yang.c ���
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("���",({"yang guo","yang","guo"}));
        set("title","��Ĺ����");
        set("nickname",HIY"������"NOR);
        set("long", "�������������µ���������һ�۵����ڲ�ȥһ����Ӣ�ۺ�����\n");
        set("age", 35);
        set("shen", 1000000);
        set("per", 30);
        set("str", 28);
        set("int", 28);
        set("con", 30);
        set("dex", 29);
        set("max_qi", 3000000); 
        set("couple/couple_id","xiao longnv");		
        set("max_jing", 1000000); 	
        set("neili", 4000000);                   	
        set("max_jingli", 200000); 	
        set("jingli", 1000000);	
        set("max_neili", 600000);        	
        set("jiali", 30000);      	
        set("xyzx_sys/level", 1500);
        set("combat_exp", 150000000);    	
        set_skill("sword",2850);	
        set_skill("dodge",2200);	
        set_skill("unarmed",2500);
        set_skill("force", 2500);
        set_skill("yunv-shenfa", 1500);	
        set_skill("xuantie-jianfa", 1550);	
        set_skill("anranxiaohun-zhang", 1500);     	
        set_skill("quanzhen-jianfa",1500);	
        set_skill("tianluo-diwang", 1480);
        set_skill("parry", 2400);
        set_skill("yunv-xinfa",1500);	
        set_skill("literate", 2450); 
        map_skill("force", "yunv-xinfa");        	
        map_skill("sword","xuantie-jianfa");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "xuantie-jianfa");        	
        map_skill("unarmed", "anranxiaohun-zhang");              	
        set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
        (: perform_action, "unarmed.xiaohun" :),
        (: perform_action, "unarmed.jingtao" :),
        (: perform_action, "unarmed.tuo" :),		
        (: perform_action, "sword.haichao" :),
		(: perform_action, "sword.xunlei" :),
		(: perform_action, "sword.hai" :),
		(: perform_action, "sword.qianjun" :),
        }));
    
        create_family("��Ĺ��",3,"������");
        set("inquiry", ([
           "��Ĺ" : "���ջ�ɽ����Ӣ�۾��������������ڴ��������꣬�������£����������ڴ˳���һ�����������ӣ�",
           "������" : "������������������֮��˽�ɱ�����أ��������ô˽����ֽ��������زش˽���һ����",
           "С��Ů" : "�������Ұ��ޣ�������������",
        ]));

        setup();

        carry_object("/d/gumu/obj/buxue1")->wear();
        carry_object("/d/gumu/obj/xuantiejian")->wield();	
        carry_object("/d/gumu/obj/pao1")->wear();         
}

void attempt_apprentice(object ob)
{
     mapping fam = ob->query("family");
if (!fam || fam["family_name"] != "��Ĺ��" || fam["generation"]!=5){
                command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                return;
                }       
      if((int)ob->query_skill("yunv-xinjing", 1) < 120) {
                command("say �ڹ��ǹ�Ĺ�书֮������"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
                return;
                }   
      if((int)ob->query_int() < 30 ) {
                command("say �ҵ��书��Ҫ���ߵ����Բ���ѧ�ᡣ");
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
                command("say "+RANK_D->query_respect(ob)+"�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
                }
      if(ob->query("gender") != "����") {
                command("say �ҿ�ֻ����ͽ����ȥ�������������԰ɡ�");
                return;
                }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");         
        command("chat ��Ĺ�书���ֽ�����"+ ob->name() +"�ɱ���Ϊʦ�������ˣ�");
        command("chat* pat " + ob->query("id"));
        command("recruit " + ob->query("id"));
        ob->set("title","��Ĺ��������´���");
        ob->set("class","sworder");
}

