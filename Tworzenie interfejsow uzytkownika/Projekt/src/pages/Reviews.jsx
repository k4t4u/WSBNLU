import { motion } from 'framer-motion';

export default function Reviews() {
    const reviews = [
        {
            name: 'Adam Nowak',
            role: 'Właściciel warsztatu',
            comment:
                'System MCS znacznie ułatwił nam kontrolę nad stanami magazynowymi. Wreszcie wiemy, co mamy na stanie!',
            avatar: '🧔',
        },
        {
            name: 'Katarzyna Malec',
            role: 'Manager logistyki',
            comment:
                'Dzięki alertom o niskim stanie części nie musimy już sprawdzać wszystkiego ręcznie. Oszczędność czasu!',
            avatar: '👩‍💼',
        },
        {
            name: 'Tomasz Wójcik',
            role: 'Mechanik',
            comment:
                'Dodawanie nowych części jest szybkie i intuicyjne. Polecam każdemu, kto szuka prostego rozwiązania.',
            avatar: '👨‍🔧',
        },
        {
            name: 'Ewa Kaczmarek',
            role: 'Właściciel sklepu z częściami',
            comment:
                'Bardzo pomocny support i funkcjonalności dopasowane do realnych potrzeb branży.',
            avatar: '👩‍🔧',
        },
    ];

    return (
        <motion.div
            className="max-w-6xl mx-auto px-6 py-16 bg-gray-50 dark:bg-gray-900 text-gray-900 dark:text-gray-100"
            initial={{ opacity: 0, y: 10 }}
            animate={{ opacity: 1, y: 0 }}
            exit={{ opacity: 0, y: -10 }}
            transition={{ duration: 0.4 }}
        >
            <motion.h1
                className="text-4xl font-bold mb-8 text-center"
                initial={{ opacity: 0, y: 20 }}
                animate={{ opacity: 1, y: 0 }}
                transition={{ delay: 0.2 }}
            >
                Opinie użytkowników
            </motion.h1>

            <motion.p
                className="text-lg mb-12 text-center max-w-3xl mx-auto text-gray-700 dark:text-gray-300"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.4 }}
            >
                Zobacz, co mówią nasi klienci o systemie zarządzania częściami samochodowymi.
            </motion.p>

            <motion.div
                className="grid md:grid-cols-2 gap-8"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.6 }}
            >
                {reviews.map((review, index) => (
                    <motion.div
                        key={review.name}
                        className="bg-white dark:bg-gray-800 rounded-xl shadow-md hover:shadow-xl dark:shadow-gray-700 dark:hover:shadow-gray-600 p-6 transition duration-300"
                        whileHover={{ scale: 1.03 }}
                        transition={{ type: 'spring', stiffness: 300 }}
                    >
                        <div className="flex items-start gap-4">
                            <div className="text-5xl">{review.avatar}</div>
                            <div>
                                <h2 className="text-lg font-semibold">{review.name}</h2>
                                <p className="text-sm text-gray-500 dark:text-gray-400 mb-2">{review.role}</p>
                                <p className="text-gray-600 dark:text-gray-300 text-sm">{review.comment}</p>
                            </div>
                        </div>
                    </motion.div>
                ))}
            </motion.div>
        </motion.div>
    );
}
