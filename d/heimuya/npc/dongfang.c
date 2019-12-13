// dongfang.c
// by mei
#include <ansi.h>
inherit NPC;
void reset();
int do_answer(string str);
void do_dest(object ob);
void do_give(object ob);
void create()
{
    set_name("��������", ({"dongfang bubai", "dongfang"}));
    set("nickname", HIY "������̽���" NOR );
    set("gender", "����");
    set("age", 46);
    set("shen",-4000);
    set("long",
        "������������̽������ų����˿ɵУ������һ�ƺ�Ϊ���������ܡ���\n");
    set("attitude", "peaceful");
    set("str", 31);
    set("int", 80);
    set("con", 86);
    set("dex", 100);
    set("per",44);
    set("no_magic",1);
    set("chat_chance", 1);
    set("chat_msg", ({
        "��������̾�˿����������� ���� ���������ѵ����˳�����?\n",
        }));
    set("inquiry", ([
        "��������" : "������ܰ���ȡ�ÿ��������ϲᣬ��һ������л�㡣\n",
              "��" : "������˿���SIGH��������\n",
    ]));
    set("qi", 10000);
    set("max_qi", 10000);
    set("jing", 5000);
    set("max_jing", 5000);
    set("jingli", 10000);
    set("max_jingli", 10000);
    set("neili", 10000000);
    set("max_neili", 20000);
    set("jiali", 800);
    set("combat_exp", 82800000);

    set_skill("force", 850);              // �����ڹ�
    set_skill("dodge", 850);              // ��������
    set_skill("parry", 850);              // �����м�
    set_skill("sword", 850);              // ��������
    set_skill("pixie-jian", 450);         // PiXieJian
    set_skill("literate",1000);           // ����ʶ��
    set_skill("kuihua-xinfa", 100);       // �����ķ�
    map_skill("force"  , "kuihua-xinfa");
    map_skill("sword", "pixie-jian");
    map_skill("dodge"  , "pixie-jian");
    map_skill("parry"  , "pixie-jian");
    set_temp("apply/shade_vision",1);
    create_family("�������", 2, "����");
    set("chat_msg_combat", ({
    (: exert_function, "recover" :),
    }) );

    setup();
    carry_object(__DIR__"obj/zhen")->wield();
    carry_object("/d/quanzhou/obj/xiuhua")->wield();
    carry_object(__DIR__"obj/hongchouxiaoshan")->wear();
}
void init()
{
    ::init();
    if (this_player()->query_temp("kill yang")){
          command("say �󵨿�ͽ������ɱ�Ұ��򣬿���!\n");
          call_out("kill_ob", 0, this_player()); 
          this_player()->fight_ob(this_object());
          COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
    }else
    add_action("do_answer","answer");
}

int accept_fight(object me)
{
        if (me->query_temp("fight/��") > 1){
            this_object()->kill_ob(me);
            me->kill_ob(this_object());
            return 1;
        }else{
        command("say ������"+me->name(1)+"���������ǹ��ϵ�--���������ɣ��Ҳ�����ƽϣ�\n�������������ҹ��Ҿ�ɱ���㡣\n");
                me->add_temp("fight/��", 1);
        }                
        return 0;
}

int accept_object(object who, object ob)
{
        if ( (string) ob->query("id") =="kuihua baodian1" ) {
                message_vision("�������ܿ��˿�$N�������ؼ������˵�ͷ��˵����\n"+
                               "�ѵ��㽫�����ͻء������ҵĶ����Ҿ������ˡ�\n"+
                               "�����һ�����߲��ܽ��⻨���꣬��������߻�����\n", who);
                who->set_temp("tmark/��", 1);
                return 1;
        }
        if ( (string) ob->query("id") =="rousisuo" ) {
             if ((int)who->query_temp("tmark/��")){
                message_vision("�������ܿ��˿�$N��������˿�������˵�ͷ��˵�����ܺã���λ"+RANK_D->query_respect(who)+",\n����������⻨�־����м��仨(answer)?\n",who);
                who->set_temp("tmark/��", 2);
                call_out("do_dest",10,who);
                return 1;
             }else
                message_vision("�������ܿ��˿�$N��������˿�������˵�ͷ��˵����л�ˡ�\n",who);
                return 1;
        }
        return 0;
}

mixed weapon_ob(object me,object victim,int damage)
{
      object weapon;
      if (!weapon=me->query_temp("weapon"))
      {
          weapon=new("/d/heimuya/npc/obj/zhen");
          weapon->move(me);
          command("wield zhen 1");
          weapon=new("/d/heimuya/npc/obj/zhen");
          weapon->move(me);
          command("wield zhen 1");
      }
      return 0;
}
int do_answer(string str)
{
      int i,j;
      object ob=this_player();
      object me=this_object();
      if (ob->query_temp("tmark/��")!=2)  return 0;
      if (!str || !sscanf(str,"%d",i)) return notify_fail("����������Ц�ؿ�����:���ѽ!\n");
      message_vision("$N���������ش𵽣�"+CHINESE_D->chinese_number(i)+"�仨��\n",ob);
      ob->delete_temp("tmark/��");
      j=ob->query("birthday");
      j=j%90+10;
      if (i==j){
          message_vision("$N���˵�������$n��ͷ���ԣ��Ҿ�����"+CHINESE_D->chinese_number(i)+"�仨��\n",me,ob);
          call_out("do_give",1,ob);
      }else{
          message_vision("$N����ɫ΢�䣺��������Ϲ���ۣ�����ͳ�ȫ��ɣ�\n",me);
          me->kill_ob(ob);
          ob->fight_ob(me);
      }
      return 1;
}
void do_dest(object ob)
{
      object me=this_object();
      if( !ob || !ob->query_temp("tmark/��") ) return;
      ob->delete_temp("tmark/��");
      if ( environment(ob) != environment() ) return;

      message_vision("$N��Ŀ¶�׹⣺֧֧����ģ����������Ʋ�������Ļ��־\n",this_object());
      me->kill_ob(ob);
      ob->fight_ob(me);
}
void do_give(object ob)
{
     object obj;
     if( !ob || environment(ob) != environment() ) return;
     obj=new(__DIR__"obj/kuihua2");
     obj->set("owner",ob->query("id"));
     if (!obj->move(ob))
        destruct(obj);
     message_vision("$N����$nһ��"+obj->query("name")+"��\n",this_object(),ob);

                ob->add_temp("study_book", 1);
}

void reset()
{
    this_object()->remove_all_killer();
}

