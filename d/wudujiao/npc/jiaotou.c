// jiaotou.c
// ɳǧ��
// by star
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ɳǧ��", ({ "sha qianli", "sha" }));
        set("nickname", HIG "����" NOR);
        set("long",@LONG
�������嶾�̵Ļ�������ɳǧ���Ŀ��࣬���������ڽ���ת����ļ
���ڣ����ڵ����ǵ����Ź���
LONG
        );
        set("title","�嶾�̻�������");
        set("gender", "����");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 40);
        set("combat_exp", 1000000);
        set("score", 5000);

        set_skill("force", 150);
        set_skill("wudu-shengong", 150);
        set_skill("dodge", 150);
        set_skill("wudu-yanluobu", 150);
        set_skill("unarmed", 180);
        set_skill("qianzhu-wandushou", 200);
        set_skill("parry", 170);
        set_skill("sword", 170);
        set_skill("wudu-goufa", 170);
        set_skill("duji", 180);
        set_skill("literate", 60);
//        set_skill("hammer", 60);
//        set_skill("jinshe-chui", 70 );
//      set_skill("strike", 200 );


        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
//        map_skill("hammer", "jinshe-chui");

        create_family("�嶾��", 13, "��������");

        setup();

        carry_object(__DIR__"obj/ganggou")->wield();
        carry_object("/clone/cloth/cloth")->wear();

        add_money("silver",30);
}

void attempt_apprentice(object ob)
{

                  if ((string)ob->query("gender") == "����") {
                                 command("say ��λ������Ҫ����Ц�ˡ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���ǿ�ȥ�ź���ϰɣ�");
                return;
                  }

                  if ((int)ob->query("shen") > 1000) {
                                 command("say �����嶾�̵��ӱ����ĺ�������");
                command("say �ҽ̵��ӹ�����������������α����");
                return;
                  }
if ((int)ob->query("age") > 18 ) {	
command("say �ҽ����躢֮ͯ����֮!");        	
return;
}


          command("chat* heihei "+ob->query("id"));
          command("chat �õ����嶾�̷����󣬳ư�����ָ�տɴ��ˡ�");

        command("recruit " + ob->query("id"));
        ob->set("class", "none");
         ob->set("title",HIY"�嶾��ͽ"NOR);
       return;
}

