// By zjb@ty 2002-5-15

inherit ITEM;
void create()
{
        set_name(HIB"��Ѫֹʹ��"NOR, ({ "qufu shengjisan","shengjisan","san"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�Ż�Ѫֹʹ��,��˵���������˵�ʥҩ!\n");
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

  if (me->query("daoxin/dex")) {
  if (me->query("daoxin/dex")>=3) {
    shoubi = random(3);
    me->add("dex",shoubi);
    me->add("daoxin/dex",-shoubi);    
    tell_object(me,HIC"��е���������ƺ��õ���!\n"NOR); 
    } else {
    me->add("dex",1);
    me->add("daoxin/dex",-1);
    tell_object(me,HIG"��е���������ƺ��õ���!\n"NOR); 
}
}
    me->add("combat_exp",random(10000));
    me->add("potential",random(5000));

    message_vision(HIY"$N�ó���Ѫֹʹ��������ȥ,�о�����һ��ů�����,��һ��˵�����������\n"NOR,me);
       destruct(this_object());
       return 1;
}

