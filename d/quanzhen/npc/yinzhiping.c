// yinzhiping.c  ��־ƽ

#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("��־ƽ", ({"master yin","yin zhiping", "yin", "zhiping"}));
        set("gender", "����");
        set("age", 28);
        set("long",
             "�������ǹڣ�ü��Ŀ�㣬���ȸ߻������׳�����\n"
                "����ȫ��̵����������������δ��һ����\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 21);
        set("int", 19);
        set("con", 21);
        set("dex", 19);
        set("per", 28);

        set("chat_chance", 1);
        set("chat_msg", ({
             "��־ƽ˵������������Ĺ�в�֪��ʲô������ȥ��������\n",
             " ��־ƽ�૵�����С��Ů�������µ�һ��Ů����\n",
//            (: random_move :),
        }));

        
        set("qi", 800);
        set("max_qi", 800);
        set("jing", 1100);
        set("max_jing", 1100);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 80);
        
        set("combat_exp", 900000);
        set("score", 80000);
 
        set_skill("force", 120);             // �����ڹ�
        set_skill("tiangang-zhengqi", 120);    //�������
        set_skill("unarmed", 120);           // ����ȭ��
         set_skill("kongming-quan", 120);     //����ȭ 
        set_skill("dodge",120);              // ��������
        set_skill("qixing-huanwei", 120);        //���ǻ�λ
        set_skill("parry", 120);             // �����м�
        set_skill("sword", 120);             // ��������
        set_skill("quanzhen-jianfa", 120);        //����� 
        set_skill("taoism",120);           //��ѧ�ķ�  
        set_skill("literate",120);           //����д�� 
        set_skill("qixing-array",100);       //����������

        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("ȫ���", 3, "����"); 
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/obj/greenrobe")->wear();

}

void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if(ob->query("family/master_id")=="master yin"&&ob->query_temp("warn_time")<time())
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
         if((int)ob->query("shen")<0){
         command("say ��ȫ������������������ɣ�"+RANK_D->query_respect(ob)+
                                "��Ʒ��ʵ�����˻��ɡ�");
         command("say "+RANK_D->query_respect(ob)+
                                "�����Ȼ�ȥ���������°ɡ�");
         return;
         }
        command ("smile");
        command("say �ðɣ��Ҿ��������ˣ����Ҫ�úù����ȫ��̣�");
        command("recruit " + ob->query("id"));
        if( (string)ob->query("class") != "taoist")
                ob->set("class", "taoist"); 
        if (this_player()->query("age")<20)
        {
        if((string)this_player()->query("gender")!="Ů��")
                this_player()->set("title","ȫ��̵�ͯ");
        else
                this_player()->set("title","ȫ���С����");
        }
        else {
        if((string)this_player()->query("gender")!="Ů��")
                this_player()->set("title","ȫ��̵�ʿ");
        else
                this_player()->set("title","ȫ��̵���");
        } 
}

