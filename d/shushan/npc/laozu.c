//����ɽ�ɡ�mhxy-yushu 2001/2
// lilong alter 2002.01.19
inherit NPC;
inherit F_MASTER;
int ask_back();
#include <ansi.h>
void create()
{
       set_name("��������", ({"master jingxu","jingxu", "master"}));
       set("title",HIC"��ɽ�ɿ�ɽ��ʦ"NOR);
       set("gender", "����");
       set("age", 220);
        set("class", "xiake");
    set("attitude","peaceful");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ��");
       set("per", 26);
        set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
        set("int", 30);
        set("max_qi", 30000000);
       set("max_jing", 30000000);
       set("neili", 30000000);
	   set("jingli", 30000000);
       set("max_neili", 30000000);
        set("max_jingli", 30000000);
		set("combat_exp", 2100000000);
         set("jiali",100000);
		 set("no_suck", 1);
       set_skill("literate", 2000);
       set_skill("dodge", 2000);
       set_skill("parry", 2000);
       set_skill("unarmed", 2000);
        set_skill("fumozhang", 2000); 
        set_skill("songhe-sword", 2000);
       set_skill("yujianshu", 2000);
       set_skill("shushan-force", 2000);
        set_skill("sword",2000);
        set_skill("force", 2000);
     set_skill("zuixian-steps",2000);
       map_skill("force", "shushan-force");
        map_skill("sword", "yujianshu");
        map_skill("parry", "yujianshu");
        map_skill("dodge", "zuixian-steps");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
                  (: perform_action,"unarmed","feilong" :),
                (: perform_action, "sword", "fumo" :),
        }) );
        set("inquiry", ([
                 "��ȥ" : (: ask_back :),
                 "back" : (: ask_back :),
         ]) );
        create_family("��ɽ��", 1, "����");
        setup();

       carry_object("/clone/cloth/cloth")->wear();
 carry_object("/d/shushan/obj/qixing")->wield();
   }

void attempt_apprentice(object ob)
{       ob=this_player();
       if( (string)ob->query("family/family_name")=="��ɽ��") {
        if ((int)ob->query("combat_exp") < 8000000 ) {
        command("say �����ѧ��Ϊ�����������ҵ��з���������\n");
        return;
        }
       if( (int)ob->query_skill("shushan-force", 1) < 800 ) {
        command("say ��λ" + RANK_D->query_respect(ob) + "����ڹ����������,�㻹���ҽ�ʥ�������Ű�!\n");
        command("sigh");
        return;
        }
       command("smile");
       command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
       command("recruit " + ob->query("id") );
       ob->set("shushan/wanjian_perform",1);
       return;
        }
       command("shake");
       command("say ���Ǳ��ɵ���?��" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
       return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "��ɽ�������洫��");

}

        return 0;
}
int ask_back()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "��ɽ��")
    {
    command("say ���ֲ�����ɽ�ɵģ������������");
    return 1;
    }
    if(ob->query("family/master_name") == "��������" )
    {
    command("say �����ȥ�����ð�!�������ȥ!\n,say �´ν���ʱ�Ͳ�Ҫ��ô�鷳��,ȥ�ؾ���(push ���)�Ϳ����ˡ�\n");
    ob->move("/d/shushan/cangjingge");
    return 1;
    }
}
