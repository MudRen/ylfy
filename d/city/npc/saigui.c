
inherit NPC;

int random2 (int i)
{
  return (random(i)+uptime()) % i;
}

void create()
{
  set_name("����", ({ "sai gui", "gui" }) );
  set("race", "Ұ��");
  set("gender", "����");
  set("age", 2);
  set("long", "һֻ�����ڵ����ꡣ\n");
  set("attitude", "friendly");
  set("str", 20+random2(2));
  set("int", 20+random2(2));

  set("dex", 20);

  set("per", 20);
  set("limbs", ({ "ͷ��", "צ��", "β��" }) );
  set("verbs", ({ "bite"}) );

  setup();
}

