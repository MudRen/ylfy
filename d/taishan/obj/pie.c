// �ڱ�

#include <ansi.h>

inherit ITEM;

int do_chieat(string);
void init();

void init()
{
  add_action("do_chieat", "chieat");
}

void create()
{
  set_name( HIY "�ڱ�" NOR , ({"pie", "xian bing"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
set("no_get", 1);	
set("no_put", 1);	
set("no_drop", 1);	
set("no_give", 1);	
    set("long", "����һ�����ϵ��µ��ڱ����Ѿ��м�ǧ�����ʷ�ˣ���˵������˳��˻���Ч�ޱȣ����ǹ���������Ҳ���ܻ�������֮û��ʵ�����Ҳû��������!  ��˵����ڱ����������ϲ������Ŷ���� \n");
set("value", 2000);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}
int do_chieat(string arg)
{
  object me = this_player();

  if (arg!="pie" && arg!="xian bing")   return 0;
if (me->query("combat_exp",1)<100000000)
{
		message_vision("$N����һ���ڱ���ʹ�����ش������һ����غ��ˡ�����\n", me);
		me->die();
               CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s���ڱ������ˡ�", me->name(1)));
		destruct(this_object());
}
if (me->query("max_neili",1)<800000)
{
		message_vision("$N����һ���ڱ�����������������������Կ����ڱ���ǿ��������Ѫ�ܱ��Ѷ���������\n", me);
		me->die();
                CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s���ڱ������ˡ�", me->name(1)));
                destruct(this_object());
}
if (me->query("combat_exp",1)>100000000)
	{
  message_vision(HIG " $N���̻��ʵĳ���һ���ڱ���ͻȻ����һ�󷭹� \n" NOR, me);
  call_out("eat1",1,me);
	}
return 1;
}

int eat1(object me)
{
  message_vision(HIG " $N�������� ,ûé�ޡ�������ô�죿������\n" NOR, me);
  call_out("eat2",1,me);
  return 1;
}

int eat2(object me)
{
  message_vision(HIG " �����˲��������ˣ��͵ؽ���ɣ�\n" NOR, me);
  call_out("eat3",1,me);
  return 1;
}

int eat3(object me)
{
  write(HIG " ����һ�����ں���о��Լ���������Щ�仯��\n" NOR);
  call_out("eat4",1,me);
  return 1;
}

int eat4(object me)
{
  write(HIG " ��ϲ�㣬���HP��������ʲô�仯��\n" NOR);
me->add("potential",10000);	
  destruct(this_object());
  return 1;
}

//   void owner_is_killed() { destruct(this_object()); }             	
