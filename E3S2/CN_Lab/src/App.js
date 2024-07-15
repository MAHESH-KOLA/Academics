import React, { useEffect, useState } from 'react';
import axios from 'axios';

function App() {
    const [orders, setOrders] = useState([]);

    useEffect(() => {
        axios.get('http://localhost:3001/getOrders')
            .then(response => setOrders(response.data))
            .catch(err => console.error(err));
    }, []);

    return (
        <div>
            <h1>orders</h1>
            <ul>
                {orders.map(order => {
                   return  <li key={order._id}> {order.id}-{order.Name} - {order.place}</li>
                })}
            </ul>
        </div>
    );
}

export default App;
