#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_me();
void create()
{
        set_name("���ŵ�", ( {"qiong yadie","qiong"} ) );
        set("long","����ɴ��ˣ�������ɽ�����������޴ӵ�֪��������\n" );
        create_family("�����", 47 , "������");
        set("title",HIG"��"HIM"��"HIR"��"NOR);
        set("attitude", "peaceful");
        set("age", 35);
        set("gender", "Ů��");
        set("shen_type", 1);
        set("chat_chance", 1);
        set("no_drop",1);
        set("con", 30);
        set("dex", 30);
        set("int", 30);
        set("str", 30);
        set("per", 40);
        set("ker", 40);
        set("qi", 400000);
        set("max_qi", 400000);
        set("jing", 10000);
        set("max_jing", 10000);
        set("jingli", 10000);
        set("max_jingli", 10000);
        set("neili", 300000);
        set("max_neili", 300000);
        set("jiali", 100);

        set("combat_exp", 100000000);

        set_skill("dodge", 1250);
        set_skill("force", 1240);
		set_skill("taoism", 1200);
        set_skill("meinv-shenquan",1000);
        set_skill("literate",1100);
        set_skill("parry", 1050);
        set_skill("unarmed", 1050);
        set_skill("sword", 1200);
        set_skill("dieyi-jianfa", 1280);
        set_skill("wudie-xinjing", 1250);
        set_skill("wudie-bu", 1090);
        map_skill("force", "wudie-xinjing");
        map_skill("dodge", "wudie-bu");
        map_skill("parry", "dieyi-jianfa");
        map_skill("sword", "dieyi-jianfa");

        set("inquiry", ([
                "������" : "������ΨŮ�Ե��Ӳ���ѧ�������е������ལ����ã�\n",
                "����" : (: ask_me :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: command("perform wudie") :),
                (: command("exert duan") :),
        }) );


        setup();

        carry_object("d/wudie/obj/dieyi")->wear();
        carry_object("d/wudie/obj/jian")->wield();

}
void attempt_apprentice(object who)
{
        if (who->query("gender") != "Ů��"){
                command("say �����ˣ�������������");
                return 0;
        }

        if ((int)who->query("per") < 25 ){         //ԭ�����ж���!=30
                command("say �������ɽֻ����ɫ��Ⱥ��Ů�ӣ�\n");
                return 0;
        }


        command("say �ðɣ����ӣ����������ˣ�\n");
        command("say �����ɽ����������������ҷ������������ʲô�ϸ��Ҫ�ϴ�������\n");
        command("recruit " + who->query("id"));

}
void init()
{
   
        ::init();
        add_action("do_learn", "learn");
        add_action("do_learn", "xuexi");
}

int do_learn()
{
        object who;
        who = this_player();
        if( who->query("shen") > 1000 || who->query("shen") < -1000){
        command("say ������ƺ����ԣ����Լ����һ�£�");
        return 1;
        }
}

int ask_me()
{
    if (this_player()->query_temp("book_4") == 2){
        if(random(1) == 0 ){
        command("sigh " + this_player()->query("id"));
        command("tell " + this_player()->query("id") + " ����˵���ࣿ������\n
        �������Ǽ���ǰ���ɵ���ͽ������������ɽׯ����ŵ���Ϊ��������\n
        ������ܰ�ɱ�ˣ���һ����л��\n
        ��˵����а�ɸ��ֻ���һ��");
        this_player()->set_temp("book_4",30);
        }else{
        command("tell " + this_player()->query("id") + " ����˵���ࣿ������\n
        ���������Ұ�ͽ�ܣ�����ǰΪʦ������ɽ׷���������䡣����\n
        ������һȥ�޹飬��֪������");
        this_player()->set_temp("book_4",31);
        }
    }else{
        command("say ��������");
        this_object()->kill_ob(this_player());
    }
}

int accept_object(object who, object ob)
{
        object book;
        if ((int)who->query_temp("book_4") == 44 ){
        if ( (string) ob->query("name") =="�����ʬ��") 
        {
                message_vision("���ŵ���ϸ������һ��$N������ʬ���Ц����\n"
                               "�ǣ��ǣ��ǣ���л��Ϊ��ׯ��ȥ��ͽ���Ȿ���Ǹ�л��ġ�\n", who);
                destruct(ob);
                book = new("/clone/book/unarmedbook");
                book -> move(this_player());
                command("rumor " + this_player()->query("name") + "�õ�һ���������飡");
                return 0;

        }
        }
}




