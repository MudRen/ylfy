// hetieshou.c
// ������
// by victori
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_me();
int ask_box();

void create()
{
        set_name("������", ({ "he tieshou", "he" }));
        set("nickname", HIG "�嶾����" NOR);
        set("long",@LONG
��������һ��һ��ۺ�ɴȹ��Ц���绨����Ů�������ü���ѩ�ף�üĿ�续��
����һ˫���۵����㣬�ֽ��϶����������Ľ���˭���뵽�������嶾�̵Ľ�
�������֣�������ʿ�������޲������ľ���
LONG
        );
        set("title","�嶾�̽���");
        set("gender", "Ů��");
        set("age", 25);
set("shen", -10000000);          	
        set("str", 120);
        set("int", 30);
        set("con", 80);
        set("dex", 30);
         set("per", 36);
set("max_qi", 100000);      	
set("max_jing", 15000);	
set("neili", 100000);               	
set("max_neili", 50000);	
        set("jiali", 300);
        set("combat_exp", 40000000);
        set("score", 500000);
        set("box_count",1);
        set("tieshao_count",1);

        set_skill("force", 800);
        set_skill("wudu-shengong", 600);
        set_skill("dodge", 900);
        set_skill("wudu-yanluobu", 650);
        set_skill("unarmed", 700);
        set_skill("qianzhu-wandushou", 650);
        set_skill("parry", 900);
        set_skill("sword", 800);
        set_skill("wudu-goufa", 600);
        set_skill("duji", 800);
        set_skill("literate", 1500);

 



        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");


set("chat_chance_combat", 80);	
         set("chat_msg_combat", ({
                (: perform_action, "sword.suo" :),
                (: perform_action, "unarmed.qzwd" :),
                (: exert_function, "recover" :),
        }) );

        create_family("�嶾��", 11, "����");

        setup();
        set("inquiry", ([
                "�򶾿�": (: ask_me :),
                "����": (: ask_me :),
                "��ɳ��Ӱ": (: ask_box :),
         ]) );

        carry_object(__DIR__"obj/jingou")->wield();
        carry_object(__DIR__"obj/skirt")->wear();

        add_money("gold",10);
}
int ask_me()
{
        object ob;
        if ((string)this_player()->query("family/master_id")!="he tieshou"){
               command("say �򶾿��˱���ʥ�أ������̳���֮����˲��ý��롣");
               return 1;
         }
        if(query("tieshao_count")< 1 ){
              command("say �������ˣ��������Ѿ��������ˡ�");
              return 1;
        }
        command("say �򶾿��������쳣��ǧ��ҪС�İ���\n");
        command("say ��ֻ�������ҵ���������ƾ�����ɽ��붴�У�");
        ob = new(__DIR__"obj/tieshao");
        ob->move(this_player());
        add("tieshao_count",-1);
         remove_call_out ("give_tieshao");
         call_out ("give_tieshao", 900); // 15 ����
        return 1;
}
int ask_box()
{
       object ob;
       if ((string)this_player()->query("family/master_id")!="he tieshou"){
               command("say ���˱����ر������ײ�����˵ġ�");
               return 1;
        }
       if(query("box_count")< 1 ){
              command("say �������ˣ���ɳ��Ӱ���Ѿ��͸������ˡ�");
              return 1;
        }
       command("smile");
       command("say ��ô����Ҫ���˴���𣿿ɱ��������嶾�����簡��");
       command("say ��ɳ��Ӱ����ȥ�ɣ������ǳ��������嶾�̵�������");
       ob = new(__DIR__"obj/hanshasheying");
       ob->move(this_player());
       add("box_count",-1);
       ob->set("own_name",this_player()->query("id"));
        remove_call_out ("give_hssy");
        call_out ("give_hssy", 900); // 15 ����
       return 1;
}

void attempt_apprentice(object ob)
{

          if ((string)ob->query("gender") == "����") {
                                 command("say ��λ������Ҫ����Ц�ˡ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���ǿ�ȥ�ź���ϰɣ�");
                return;
                  }

          if ((int)ob->query("shen") > -100000) {
                                 command("say �����嶾�̵��ӱ����ĺ�������");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ĵ�������ϧ���ҽ�û��Ե�ְ���");
                return;
                  }

        if ((string)ob->query("family/family_name") != "�嶾��")        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���Ǳ��̵��ӣ�������ذɣ�");
                return;
                  }

        if ((int)ob->query_skill("duji", 1) < 300) {
                command("say ���嶾�̵����Զ�ɱ�ˣ���ϰ��������Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵľ�ѧ��");
                return;
        }
        if ((int)ob->query_skill("wudu-shengong", 1) < 300) {
                command("say ����嶾�񹦻�ѧ�Ĳ�������");
                return;
        }

//        command("chat �ٺٺٺ٣���������");
          command("chat �ðɣ���Ȼ��˱���������������ͽ�ܡ�");
          command("chat ����һ�죬Ҫ�������˶�֪�������嶾�̵�����������");
        command("recruit " + ob->query("id"));
        ob->set("class", "none");
         ob->set("title",HIY"�嶾�̳���"NOR);
        return;
}
void give_hssy()
{
        set("box_count",1);
}
void give_tieshao()
{
        set("tieshao_count",1);
}

