

// sserver.c

inherit F_CLEAN_UP;
int test_attack(object me,object target,int mx, int my);
object offensive_target(object me);
// This function selects a random target for offensive spells/functions.

object offensive_target(object me)
{
	int sz,i;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if(this_object()->is_magic())
	{
		sz = sizeof(enemy);
		if( sz > 4 ) sz = 4;
		if( sz > 0 ) return enemy[random(sz)];
		else return 0;

	}
	if(!this_object()->perform_distance()){
		//��perform�Ĺ����������������Ĺ�������
		for(i=0;i<sz;i++){
			if(test_attack(me,enemy[i],me->query_temp("map/x"),me->query_temp("map/y"))) 
				return enemy[i];
			else continue;
		}

		return 0;
	}
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int test_attack(object me,object target,int mx, int my)//this_object������
{

	int vx,vy,xx,yy,attack_distance;

	object weapon;
	if(!target) return 0;
	if(!target->is_fighting()) return 0;
	if(!objectp(target))       return 0;
	if(!environment(target)||environment(me)!=environment(target)) return 0;
	if(!mx||!my) return 0;
	vx=target->query_temp("map/x");
	vy=target->query_temp("map/y");
	//mx=me->query_temp("map/x");
	//my=me->query_temp("map/y");
	if(!vx||!vy) return 0;
	xx=mx-vx;yy=my-vy;
	if(xx<0) xx*=-1; if(yy<0) yy*=-1;
	weapon=me->query_temp("weapon");
	if(!objectp(weapon)){//����ֻ�ܹ���ǰ�������ĸ�����
		if((xx>1)||(yy>1)) return 0;//���볬��1,û������
		if(xx==1&&yy==1)   return 0;//б����
		return 1;
	}
	else
	{
		attack_distance=weapon->query("attack_distance");
		if(attack_distance>=2){
			if(xx==2&&yy==2)   return 0;//б����2��
			if(xx>2||yy>2)     return 0;//���볬��2
			if(xx==2&&yy!=0||yy==2&&xx!=0) return 0;

		}
		else{
			if(xx>1||yy>1) return 0;
		}
		return 1;
	}
	return 0;


}

