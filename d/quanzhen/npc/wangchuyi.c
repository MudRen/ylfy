//wangchuyi.c  ����һ
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("����һ", ({"master wang","wang chuyi", "wang", "chuyi"}));
        set("nickname",HIC"������"NOR);
        set("gender", "����");
        set("age", 48);
        set("long",
             "����ü��Ŀ�������������Ժ��룬����һ��ʮ���������ε���ʿ��\n"
                "�����Ƕ���վ��ƾ��������ȣ�ʹһ�С���ں�Ҷ�����������µ������������ӡ�\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 32);
        set("int", 29);
        set("con", 32);
        set("dex", 29);

        set("chat_chance", 1);
        set("chat_msg", ({
                "����һ˵������ȫ����������£�ʢ�����ò�˥����\n",
                "����һ̾�˿��������������µ���ûһ���ǿ���֮�ţ��������Ǻá�\n",
             "����һ�૵��������������ȫ��������ϳ˵������������ɵ�����\n",
//              (: random_move :),
        }));
        set("inquiry", ([
                "�������":"�������輯����֮�����Ͷ�Ϊһ���������޵С���\n",
        ]));

        set("qi", 1600);
        set("max_qi", 1600);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 120);
        
        set("combat_exp", 4000000);
        set("score", 200000);
         
        set_skill("force", 290);             // �����ڹ�
        set_skill("tiangang-zhengqi", 290);    //�������
        set_skill("unarmed", 300);           // ����ȭ��
        set_skill("kongming-quan", 280);    //����ȭ 
        set_skill("dodge", 300);             // ��������
        set_skill("qixing-huanwei", 300);       //���ǻ�λ
        set_skill("parry", 280);             // �����м�
        set_skill("sword", 290);             // ��������
        set_skill("quanzhen-jianfa",290);        //����� 
        set_skill("taoism", 290);            //��ѧ�ķ�  
        set_skill("literate",290);           //����д��
        set_skill("qixing-array",310);

        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongmingquan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("ȫ���", 2, "����");
        

set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );


        setup();
        
       carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/obj/greyrobe")->wear();
}

void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if(ob->query("family/master_id")=="master wang"&&ob->query_temp("warn_time")<time())
        if((ob->query("PKS")>ob->query("kar")&&(int)ob->query("shen")<=-100)
        ||(ob->query("PKS")<ob->query("kar")&&(int)ob->query("shen")<=-10000))
   
       { ob->add("hao_warning",1);
         ob->set_temp("warn_time",time()+300);
         command("heng "+ob->query("id"));
         command("say �������ڽ���ɱ��Խ����������Ϊ��Ī��Ϊʦû�о������㣡");         
       }
        if((int)ob->query("hao_warning") > 3)
        {
                command("chat "+HIR+ob->query("name")+"ɱ��Խ��������Ϊ������ʦ�ţ��ӽ��Ժ�����ȫ��̵ĵ��ӡ�\n"NOR);
                command("expell "+ ob->query("id"));
                this_player()->set("title","ȫ���" + RED + "��ͽ" NOR);    
                ob->delete("hao_warning");    
        }
}               
              
void attempt_apprentice(object ob)
{

        object me  = this_object();
        mapping ob_fam  = ob->query("family");
        mapping my_fam  = me->query("family");

        
        if ( ob_fam["generation"] <= my_fam["generation"] )
        {
                command("say " + RANK_D->query_respect(ob) + "��ƶ������ҵ� !");
                return;
        }


        if ((int)ob->query_str() < 28 || (int)ob->query_con() < 28) {
                command("say ����ʿ��Ҫ�ܳԿ����ͣ������徲���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ���ʿ��");
                return;
        }
        if ((string)ob->query("family/family_name") != "" &&
            (string)ob->query("family/family_name") != "ȫ���") {
                command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α������ݱ������أ�");
                return;
        }
       if ((int)ob->query_skill("tiangang-zhengqi", 1) <120) {
                command("say ��ȫ������ڼ��书���������ڹ��ķ���"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ������������϶��µ㹦��");
                return;
       }
       if ((int)ob->query_skill("qixing-huanwei", 1) < 100) {
                command("say �ұ������Ṧ����������Ṧ��"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ�������ǻ�λ�϶��µ㹦��");
                return;
       }
       command("smile");  
       command("say �ðɣ������㻹�ǿ���֮�ţ�ƶ�����������ˡ�");
       command("recruit " + ob->query("id")); 
       ob->set("title","ȫ����������˰�ͽ");
       ob->set("class","sworder");               
}


