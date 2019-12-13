//qizhicheng.c  ��־��
#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("��־��", ({"qi zhicheng","qi", "zhicheng"}));
        set("master", "������");
        set("gender", "����");
        set("age", 26);
        set("long",
             "����ò���㿡����ȴʮ��Ӣͦ���߸ߵĸ��ӣ����ܽ�׳��\n" );        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 21);
        set("int", 19);
        set("con", 21);
        set("dex", 19); 
        set("per", 20);
        set("chat_chance", 1);
        set("chat_msg", ({
            "��־��˵�����������С���˵���㺦����ʦ�磬������Ĺ���������������\n",
            "��־���૵�������ʦ�ֵ��ǵ���˼���ٺ٣����Ҳ�֪��ѽ��������\n",
//        (: random_move :),
        }));

        set("qi", 850);
        set("max_qi", 850);
        set("jing", 850);
        set("max_jing",850);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);
        
        set("combat_exp", 800000);
        set("score", 80000);
 
        set_skill("force", 120);             // �����ڹ�
        set_skill("tiangang-zhengqi", 120);    //�������
        set_skill("unarmed", 120);           // ����ȭ��
        set_skill("kongming-quan", 120);     //����ȭ 
        set_skill("dodge",130);              // ��������
        set_skill("qixing-huanwei", 130);        //���ǻ�λ
        set_skill("parry", 120);             // �����м�
        set_skill("sword", 120);             // ��������
        set_skill("quanzhen-jianfa", 120);        //����� 
        set_skill("taoism",120);           //��ѧ�ķ�  
        set_skill("literate",120);           //����д��
        set_skill("qixing-array",120);  

  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "tiangang-beidou");
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
        if(ob->query("family/master_id")=="qi zhicheng"&&ob->query_temp("warn_time")<time())
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
                this_player()->set("title","ȫ��̵�ͯ" );
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
/*                      
void unconcious()
{ 
      object me=this_player();       message_vision(HIW"\n$N��Цһ����������֪����ȫ�潣�����������˵��ͷҲ���ص�������ȥ��\n\n"NOR,this_object());        
       command("sneer");
       me->set_temp("qz/��", 1);
       destruct(this_object());
}
*/
void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "qi zhicheng" || arg == "qi")
                obj->kill_ob(me);
        else obj->fight_ob(me);
        
        me->fight_ob(obj);
}

int accept_fight(object ob)
{
        object me  = this_object();
                
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));

        if ( me->is_fighting()) return 0;

        if ( !present(ob, environment()) ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        
        return 1;
}

int checking(object me, object ob)
{
        int my_max_qi, his_max_qi;

        if ( !present(ob, environment()) ) return 1; 

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if( me->is_fighting() ) 
        {
                if ( (int)me->query("qi")*100/my_max_qi <= 80 )
                {
                   
                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi",     me->query("max_qi"));
                        me->set("jing",   me->query("max_jing"));
                        me->set("neili",  me->query("max_neili"));
                }
                       if ( present(ob, environment()) )
                        call_out("checking", 1, me, ob);
        }

        return 1;  
}


