// By zjb@ty 2002-5-15

inherit ITEM;
void create()
{
        set_name(HIG"���嵤"NOR, ({ "qili dan","dan"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����嵤,��˵���������˵�ʥҩ!\n");
                set("unit", "��"); 
                set("no_get",1);
                set("no_s",1);             
                set("no_put",1);
                set("no_give",1);   
        }
    setup();
}
void init()
{
    if (environment()==this_player())
        add_action("do_eat", "eat");
}
int do_eat(string arg)
{ 
    object fae, shangshan, mengzhu, xinxiu;
    int maxneili,neili,shoubi;
    object me = this_player();
    neili = me->query("neili");
    maxneili = me->query("max_neili");

    fae = load_object("/d/taishan/npc/fa-e");
    fae->restore();
    shangshan = load_object("/d/taishan/npc/shang-shan");
    shangshan->restore();
    mengzhu = load_object("/d/taishan/npc/meng-zhu");
    mengzhu->restore();
    xinxiu = load_object("/d/taishan/npc/xinxiu");
    xinxiu->restore();

  if(!id(arg)) return 0;  

  if( me->query("id")==fae->query("winner") )
  return notify_fail("���ǵ��񷣶�ʹ�ߣ������ҩ�ѵ�����bug��\n");

  if( me->query("id")==shangshan->query("winner") )
  return notify_fail("���ǵ�������ʹ�ߣ������ҩ�ѵ�����bug\n");

  if( me->query("id")==mengzhu->query("winner") )
  return notify_fail("���ǵ���������������������ҩ�ѵ�����bug��\n");

  if( me->query("id")==xinxiu->query("winner") )
  return notify_fail("���ǵ�������ʹ�ߣ���������ҩ�ѵ�����bug��\n");
  if(me->is_busy()) return notify_fail("����һ��������û����ɡ�\n");

  if(me->query("id")!=query("zhuren"))
  return notify_fail("��õ�ҩ����������,��Ը�ƨ!!\n");

  if (me->query("daoxin/con")) {
  if (me->query("daoxin/con")>=3) {
    shoubi = random(3);
    me->add("con",shoubi);
    me->add("daoxin/con",-shoubi);    
    tell_object(me,HIC"��е���������ƺ��õ���!\n"NOR); 
    } else {
    me->add("con",1);
    me->add("daoxin/con",-1);
    tell_object(me,HIG"��е���������ƺ��õ���!\n"NOR); 
}
}
    me->add("max_neili",random(100));
    me->add("max_jingli",random(100));
    message_vision(HIM"$N�ó����嵤������ȥ,�о�����һ��ů�����,��һ��˵�����������\n"NOR,me);
       destruct(this_object());
       return 1;
}


