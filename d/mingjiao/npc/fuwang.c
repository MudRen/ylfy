// fuwang.c ��������
#include <ansi.h>
inherit NPC;
object ob = this_object();
void create()
{
        set_name("ΤһЦ",({"wei yixiao","wei","fuwang"}));
        set("title","���̻��̷���");
        set("long", 
           "���������̵��Ĵ󻤽̷��������ۣ������ġ�\n"
                "��һ�����������ݸ�����Ӣ�������������������ഺ��Ϣ��\n");
        set("age", 34);
        set("nickname",GRN"��������"NOR);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 25);
        set("int", 20);
        set("con", 25);
        set("dex", 35);
        set("per", 21);
        set("max_qi",3000);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 70);
        set("combat_exp", 1660000);
        set_skill("sword",170);
        set_skill("dodge",250);
        set_skill("unarmed",170);
        set_skill("literate",60);
        set_skill("force",170);
        set_skill("hunyuan-yiqi",170);
        set_skill("qingyunwu", 200);
        set_skill("blade",170);
        set_skill("shenghuo-quan",170);
        set_skill("hanbing-mianzhang",200);
        set_skill("qingyunwu",250); 
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("parry","hanbing-mianzhang");
        map_skill("unarmed","hanbing-mianzhang");

        create_family("����",34,"����");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        set("chat_chance", 2);
        set("chat_msg", ({
                (: random_move :),
CYN"ΤһЦ������˵�����Ѿ��������������ˣ��Ž����Ƕ�������õģ�\n����ͷ�������ĺ��˲����ˣ�\n"NOR,
CYN"ΤһЦ�����Ĵָ���������Ž������������屡���죬�书�������������ˣ�\nҲ���������쵱���������ӣ�\n"NOR,
        }) );
        
}
/*
void init()
{
       object ob;

       ::init();

        ob = this_player();
        if( ((int)ob->query("score") < 50 || (int)ob->query("shen") < 100 )  && ob->query("family/master_id")=="wei yixiao" )
        {
                    command("chat "+ob->query("name")+"����Ϊ�˲��Ҳ��壬�������������㣿\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","����" + RED + "��ͽ" NOR);   
        }
}
*/
void attempt_apprentice(object ob)
{
        if ((int)ob->query_int() < 35) {
                command("say " + RANK_D->query_respect(ob) +
                        "����Ƿ�ϣ���ѧ������һ���书��");
                return;
        }
        if ((int)ob->query_dex() < 40) {
                command("say " + RANK_D->query_respect(ob) +
                        "���ֲ��ݣ����������ʦ�ɡ�");
                return;

          }
       if ((string)ob->query("family/family_name")!="����" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "����������ɣ��������ȥ����");
                return;
        }        

        if ((int)ob->query("score") <= 50) {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ҽ̲������ģ����������ʦ�ɡ�");
                return;
        }
        command("say ������ �������ֵ�һ���ģ������պ󿵷����壬�������̷�����");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "shizhe")
        ob->set("class", "shizhe");
        ob->set("title","���������������½���");
}

int accept_object(object ob, object obj)
{
        object me = this_object();
        if (query("book_count") >=  80){
                if (obj->query("id") == "si huochan" )
                {
                        command("say " + ob->query("name") + "��̫лл���ˣ��������һ�����Ҹ���α������أ���ָ����һ���Ṧ�ɣ�");
                        remove_call_out("destroying");
                        call_out("destroying", 1, me, obj);
                        add("book_count",-1);
                        this_player()->improve_skill("qingyunwu",200);
                        return 1;
                }
        }
        command("smile");
        command("say �ⶫ�����ҿ�û��ʲ���á�");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;
}
