#include <ansi.h>
inherit NPC;

int give_chuan();

void create()
{
  set_name(YEL"½��"NOR, ({"lu hai", "lu"}));
  set("gender", "����");
  set("age", 76);
  set ("title","<��������ס��>  "+YEL"����һ��"NOR);
  set("attitude", "peaceful");
  set("combat_exp", 75000000);
  set("per", 25);
  set_skill("dodge", 560);
  set("max_qi",6000);
  set("max_jing",6000);
  set("max_jingi",6000);
  set("neili",18000);
  set("max_neili",18000);
  set("force_factor",25);
  set_skill("unarmed",560);
  set_skill("parry",560);
  set_skill("dodge",560);
  setup();

  set("inquiry", ([
       "here": "��֪������ʲô�ط�,����ð�����һ��������ʮ��,�������̵ġ�\n",
       "������ѩ��": (: give_chuan :),
       "��ȥ": "Ҫ���Ǹ��������ס��,���ӻ����������ô?\n",
       "����": "�������ú��׺�������,ֻ������ŵĺ���ն����ն�ϡ�\n",
       "�����":"���������Ǹ��������,����˭?\n",
       "������":"�������ú��׺�������,ֻ������ŵĺ���ն����ն��.\n",
      ]));
}

int give_chuan()
{
  object me = this_object();
  object who = this_player();
message_vision("$N��$n�ٺ�һ����Ц,˭�ܸ��Ұ�����ʲ������������,�������!\n",me,who);
return 1;
} 
