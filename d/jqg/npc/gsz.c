// gsz.c ����ֹ
// By River 99.5.25
#include <ansi.h>
inherit NPC;
string ask_gu();
void create()
{
	set_name("����ֹ", ({ "gongsun zhi", "gongsun", "zhi" }));
	set("long","��ĿӢ����͸�������߾�֮�ţ�ֻ����ɫ���ƣ����տ��¡�\n");
        set("title",HIW"����ȹ���"NOR);
	set("gender", "����");
	set("age", 45);
	set("attitude", "friendly");
	set("shen", -3000);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);
        set("per", 20);
        set("unique", 1);

set("max_qi", 500000);	
set("max_jing", 150000);	
set("neili", 3000000);	
set("max_neili", 1500); 	
set("jiali", 5000);	
set("combat_exp", 300000000);	
 
set_skill("force", 1250);      	
set_skill("dodge", 1250);	
set_skill("parry", 1250);	
set_skill("guiyuan-tunafa", 1250);	
set_skill("literate", 1220); 	
set_skill("art", 900);    	
set_skill("shuishangpiao", 1250);	
set_skill("tiezhang-zhangfa", 1250);	
set_skill("strike",1250);	
set_skill("sword", 1250);	
set_skill("liangyi-jian", 1100);	

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
map_skill("unarmed", "tiezhang-zhangfa");	
        map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");
        prepare_skill("strike", "tiezhang-zhangfa");

        set("inquiry", ([
            "���鵤": "��ҩ�޶࣬����Ҳ�������ƣ����򲻵��ѡ�����",
            "�����": (: ask_gu :),
        ]) );
set("chat_chance_combat", 200);	
set("chat_msg_combat", ({	
(: perform_action, "sword.feixue" :),	
(: perform_action, "sword.jianqin" :),	
(: perform_action, "sword.juedi" :),	
(: perform_action, "sword.ren" :),	
(: perform_action, "unarmed.tianlei" :),	
(: perform_action, "unarmed.tiezhangxianglong" :),	
(: perform_action, "unarmed.zhangdao" :),	
(: exert_function, "recover" :),	
}) );	
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

string ask_gu()
{
       object me,ob;
       me=this_object();
       ob=this_player();
       if(ob->query("combat_exp") < 200000)
         return RANK_D->query_respect(ob)+"����̫�������������ΪΣ�գ����ǲ�Ҫ�ڴ˾����ˡ�";      
         ob->set_temp("gsz_agree", 1);
         return RANK_D->query_respect(ob)+"��Ȼ�Ծ����������Ȥ��������㿴���ɡ�";
}
