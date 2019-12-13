// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
#include <ansi.h>

inherit NPC;

object room = 0;

void create()
{
  set_name("ׯ��", ({"zhuang dong", "zhuang" }));
  set("gender", "����");
  set("age", 30);
  set("per", 30);
  set("long", "һλ�ֺǺǵ�ׯ����\n");
  set("combat_exp", 5000);
  set_skill("force", 50);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
 
  setup();

}

void init()
{
  ::init();
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "exercise");
  add_action("do_exert", "exert");
  if (room == 0)
    room = environment (this_object());
}

void refuse_message (object me, object who)
{
  message_vision ("$N��$n�ֺǺǵ�һЦ���¡�\n",me,who);
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
    message_vision ("$N������������ۣ�����$n��ܡ�\n",who,me);
    refuse_message (me,who);
    return 1;
  }
  return 0;
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
    message_vision ("$N������������ۣ���ɱ$n��\n",who,me);
    refuse_message (me,who);
    return 1;
  }
  return 0;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N������������ۣ��������\n",who,me);
  refuse_message (me,who);
  return 1;
}

int do_exert(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N������������ۣ���ʩ�ڹ���\n",who,me);
  refuse_message (me,who);
  return 1;
}

int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N������������ۣ������������͵ʲô��\n",who,me);
  refuse_message (me,who);
  return 1;
}