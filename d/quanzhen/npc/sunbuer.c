//sunbuer.c �ﲻ��
#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("�ﲻ��", ({"sun buer", "sun", "buer"}));
        set("nickname", HIB"�徲ɢ��"NOR);
        set("gender", "Ů��");
        set("age", 39);
        set("long",
             "����Ŀ�ݣ���ɫ���壬�䴩һ���ɫ���ۣ�Ҳ�ڸǲ���������ɫ��\n"
             "������ȫ��������Ψһ��Ů�ԡ��徲ɢ�ˡ��ﲻ����\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 29);
        set("int", 32);
        set("con", 30);
        set("dex", 32); 
        set("per", 25);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ﲻ��˵�������Ǳ��̵��Ӳ�Ҫ���ߡ���\n",
//        (: random_move :),
        }));

        set("qi", 1200);
        set("max_qi", 1200);
        set("jing", 1250);
        set("max_jing", 1250);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 100);
        
        set("combat_exp", 2500000);
        set("score", 50000);
 
        set_skill("force", 280);             // �����ڹ�
        set_skill("tiangang-zhengqi", 280);    //�������
        set_skill("unarmed", 280);           // ����ȭ��
        set_skill("kongming-quan", 240);    //����ȭ 
        set_skill("dodge",280);              // ��������
        set_skill("qixing-huanwei", 280);        //���ǻ�λ
        set_skill("parry", 280);             // �����м�
        set_skill("sword", 280);             // ��������
        set_skill("quanzhen-jianfa", 280);        //����� 
        set_skill("taoism", 280);            //��ѧ�ķ�  
       set_skill("literate",280);           //����д��
        set_skill("qixing-array",300); 
  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("ȫ���",2,"����");
        
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
        if(ob->query("family/master_id")=="sun buer"&&ob->query_temp("warn_time")<time())
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
     mapping fam = ob->query("family");
      if (!fam || fam["family_name"] != "ȫ���"){
                command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                return;
                }       
      if((int)ob->query_skill("tiangang-zhengqi", 1) < 80) {
                command("say ��ȫ����书�ڹ��ǻ�����"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
                return;
                }  
      if((int)ob->query_skill("sword", 1) < 80) {
                command("say �㽣����ô��ҽ̵��㲻һ��ѧ�ûᡣ"); 
                command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                return;
                }
      if(ob->query_int() < 23) {
                command("say �ҵ��书��Ҫ�̸ߵ����Բ���ѧ�ᡣ");
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
                command("say ��λ"+RANK_D->query_respect(ob)+"�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
                }
      if(ob->query("gender") != "Ů��") {
                command("say �ҿ�ֻ��Ůͽ����ȥ����ʦ�������԰ɡ�");
                return;
                }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("recruit " + ob->query("id"));
        ob->set("title","ȫ����徲ɢ�˰�ͽ");
        ob->set("class","sworder");
}

